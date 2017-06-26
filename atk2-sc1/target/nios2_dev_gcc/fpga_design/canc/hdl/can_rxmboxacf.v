//////////////////////////////////////////////////////////////////////
////                                                              ////
////  can_rxmboxacf.v                                             ////
////                                                              ////
////                                                              ////
////  This file is part of the CAN Protocol Controller            ////
////                                                              ////
////                                                              ////
////  Author(s):                                                  ////
////       Center for Embedded Computing Systems                  ////
////  Graduate School of Information Science, Nagoya Univ., JAPAN ////
////                                                              ////
////                                                              ////
////  All additional information is available in the README.txt   ////
////  file.                                                       ////
////                                                              ////
//////////////////////////////////////////////////////////////////////
////                                                              ////
//// Copyright (C) 2011-2013 Authors                              ////
////                                                              ////
//// This source file may be used and distributed without         ////
//// restriction provided that this copyright statement is not    ////
//// removed from the file and that any derivative work contains  ////
//// the original copyright notice and the associated disclaimer. ////
////                                                              ////
//// This source file is free software; you can redistribute it   ////
//// and/or modify it under the terms of the GNU Lesser General   ////
//// Public License as published by the Free Software Foundation; ////
//// either version 2.1 of the License, or (at your option) any   ////
//// later version.                                               ////
////                                                              ////
//// This source is distributed in the hope that it will be       ////
//// useful, but WITHOUT ANY WARRANTY; without even the implied   ////
//// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR      ////
//// PURPOSE.  See the GNU Lesser General Public License for more ////
//// details.                                                     ////
////                                                              ////
//// You should have received a copy of the GNU Lesser General    ////
//// Public License along with this source; if not, download it   ////
//// from http://www.opencores.org/lgpl.shtml                     ////
////                                                              ////
//// The CAN protocol is developed by Robert Bosch GmbH and       ////
//// protected by patents. Anybody who wants to implement this    ////
//// CAN IP core on silicon has to obtain a CAN protocol license  ////
//// from Bosch.                                                  ////
////                                                              ////
//////////////////////////////////////////////////////////////////////
//

// synopsys translate_off
`include "timescale.v"
// synopsys translate_on
`include "can_defines.v"

module can_rxmboxacf(
  input  wire clk,
  input  wire rst,
  input  wire sample_point,

  input  wire [31:0] rxwait,
  input  wire [31:0] rxcmp,

  input  wire reset_mode,
  input  wire acceptance_filter_mode,
  input  wire extended_mode,

  input  wire [1023:0] rxmask,
  input  wire [1023:0] rxcode,

  input  wire [   4:0] rxdatawin,

  input  wire [ 127:0] rx_dt,
  input                rx_we,

  output reg  [ 127:0] rxmsgdata,
  output wire [  31:0] rx_we_ff 
);

parameter Tp = 1;

wire id_ok;
reg [31:0] rx_we_on,rx_we_on_q;
wire [31:0] rx_we_off;
reg [2:0] cnt;
reg [31:0] rx_en;
reg [31:0] rxcode_in;
reg [31:0] rxmask_in;
reg timovr;
reg [4:0] rmbox_cnt;
wire [28:0] id;

always @ (posedge clk or posedge rst)
begin
  if(rst)              rmbox_cnt <= 5'h0;
  else if(rx_we)       rmbox_cnt <=#Tp 5'h1;
  else if(~|rmbox_cnt) rmbox_cnt <=#Tp rmbox_cnt;
  else                 rmbox_cnt <=#Tp rmbox_cnt+ 5'h1;
end

wire no_byte0 = rx_dt[1*32+4] | (rx_dt[1*32+3:1*32]<4'h1); //rtr1 | (data_len<4'h1);
wire no_byte1 = rx_dt[1*32+4] | (rx_dt[1*32+3:1*32]<4'h2); //rtr1 | (data_len<4'h2);
assign id     = (rx_dt[0*32+31])? rx_dt[0*32+28:0*32]: {18'h0,rx_dt[0*32+28:0*32+18]};

always @ (*)
begin
  case(rmbox_cnt)
    5'h00: begin rxcode_in = rxcode[ 0*32+31: 0*32]; rxmask_in = rxmask[ 0*32+31: 0*32]; end
    5'h01: begin rxcode_in = rxcode[ 1*32+31: 1*32]; rxmask_in = rxmask[ 1*32+31: 1*32]; end
    5'h02: begin rxcode_in = rxcode[ 2*32+31: 2*32]; rxmask_in = rxmask[ 2*32+31: 2*32]; end
    5'h03: begin rxcode_in = rxcode[ 3*32+31: 3*32]; rxmask_in = rxmask[ 3*32+31: 3*32]; end
    5'h04: begin rxcode_in = rxcode[ 4*32+31: 4*32]; rxmask_in = rxmask[ 4*32+31: 4*32]; end
    5'h05: begin rxcode_in = rxcode[ 5*32+31: 5*32]; rxmask_in = rxmask[ 5*32+31: 5*32]; end
    5'h06: begin rxcode_in = rxcode[ 6*32+31: 6*32]; rxmask_in = rxmask[ 6*32+31: 6*32]; end
    5'h07: begin rxcode_in = rxcode[ 7*32+31: 7*32]; rxmask_in = rxmask[ 7*32+31: 7*32]; end
    5'h08: begin rxcode_in = rxcode[ 8*32+31: 8*32]; rxmask_in = rxmask[ 8*32+31: 8*32]; end
    5'h09: begin rxcode_in = rxcode[ 9*32+31: 9*32]; rxmask_in = rxmask[ 9*32+31: 9*32]; end
    5'h0A: begin rxcode_in = rxcode[10*32+31:10*32]; rxmask_in = rxmask[10*32+31:10*32]; end
    5'h0B: begin rxcode_in = rxcode[11*32+31:11*32]; rxmask_in = rxmask[11*32+31:11*32]; end
    5'h0C: begin rxcode_in = rxcode[12*32+31:12*32]; rxmask_in = rxmask[12*32+31:12*32]; end
    5'h0D: begin rxcode_in = rxcode[13*32+31:13*32]; rxmask_in = rxmask[13*32+31:13*32]; end
    5'h0E: begin rxcode_in = rxcode[14*32+31:14*32]; rxmask_in = rxmask[14*32+31:14*32]; end
    5'h0F: begin rxcode_in = rxcode[15*32+31:15*32]; rxmask_in = rxmask[15*32+31:15*32]; end
    5'h10: begin rxcode_in = rxcode[16*32+31:16*32]; rxmask_in = rxmask[16*32+31:16*32]; end
    5'h11: begin rxcode_in = rxcode[17*32+31:17*32]; rxmask_in = rxmask[17*32+31:17*32]; end
    5'h12: begin rxcode_in = rxcode[18*32+31:18*32]; rxmask_in = rxmask[18*32+31:18*32]; end
    5'h13: begin rxcode_in = rxcode[19*32+31:19*32]; rxmask_in = rxmask[19*32+31:19*32]; end
    5'h14: begin rxcode_in = rxcode[20*32+31:20*32]; rxmask_in = rxmask[20*32+31:20*32]; end
    5'h15: begin rxcode_in = rxcode[21*32+31:21*32]; rxmask_in = rxmask[21*32+31:21*32]; end
    5'h16: begin rxcode_in = rxcode[22*32+31:22*32]; rxmask_in = rxmask[22*32+31:22*32]; end
    5'h17: begin rxcode_in = rxcode[23*32+31:23*32]; rxmask_in = rxmask[23*32+31:23*32]; end
    5'h18: begin rxcode_in = rxcode[24*32+31:24*32]; rxmask_in = rxmask[24*32+31:24*32]; end
    5'h19: begin rxcode_in = rxcode[25*32+31:25*32]; rxmask_in = rxmask[25*32+31:25*32]; end
    5'h1A: begin rxcode_in = rxcode[26*32+31:26*32]; rxmask_in = rxmask[26*32+31:26*32]; end
    5'h1B: begin rxcode_in = rxcode[27*32+31:27*32]; rxmask_in = rxmask[27*32+31:27*32]; end
    5'h1C: begin rxcode_in = rxcode[28*32+31:28*32]; rxmask_in = rxmask[28*32+31:28*32]; end
    5'h1D: begin rxcode_in = rxcode[29*32+31:29*32]; rxmask_in = rxmask[29*32+31:29*32]; end
    5'h1E: begin rxcode_in = rxcode[30*32+31:30*32]; rxmask_in = rxmask[30*32+31:30*32]; end
    5'h1F: begin rxcode_in = rxcode[31*32+31:31*32]; rxmask_in = rxmask[31*32+31:31*32]; end
  endcase
end


can_acf i_can_acf
(
  .clk(clk),
  .rst(rst),
  
  .id(id),

  /* Mode register */
  .reset_mode(1'h0),
  .acceptance_filter_mode(acceptance_filter_mode),

  // Clock Divider register
  .extended_mode(extended_mode),

  /* This section is for BASIC and EXTENDED mode */
  /* Acceptance code register */
  .acceptance_code_0(rxcode_in[3*8+7:3*8]),

  /* Acceptance mask register */
  .acceptance_mask_0(rxmask_in[3*8+7:3*8]),
  /* End: This section is for BASIC and EXTENDED mode */

  /* This section is for EXTENDED mode */
  /* Acceptance code register */
  .acceptance_code_1(rxcode_in[2*8+7:2*8]),
  .acceptance_code_2(rxcode_in[1*8+7:1*8]),
  .acceptance_code_3(rxcode_in[0*8+7:0*8]),

  /* Acceptance mask register */
  .acceptance_mask_1(rxmask_in[2*8+7:2*8]),
  .acceptance_mask_2(rxmask_in[1*8+7:1*8]),
  .acceptance_mask_3(rxmask_in[0*8+7:0*8]),
  /* End: This section is for EXTENDED mode */

  .go_rx_crc_lim(1'h1),
  .go_rx_inter(1'h0),
  .go_error_frame(1'h0),

  .data0(rx_dt[2*32+0*8+7:2*32+0*8]),
  .data1(rx_dt[2*32+1*8+7:2*32+1*8]),
  .rtr1(rx_dt[1*32+4]),
  .rtr2(rx_dt[1*32+4]),
  .ide(rx_dt[0*32+31]),
  .no_byte0(no_byte0),
  .no_byte1(no_byte1),

  .id_ok(id_ok)

);

generate
  genvar i;

  for (i=0; i<32; i=i+1) begin :msgbox_afc

    assign rx_we_off[i] = rx_we_on[i] & (timovr | ~rxcmp[i]| (rxcmp[i] & ~rxwait[i]));

    if(i==0)
    begin
      always @ (posedge clk or posedge rst)
      begin
        if(rst)                   rx_we_on[i] <= 1'h0;
        else if(id_ok & rx_en[i]) rx_we_on[i] <=#Tp 1'h1;
        else if(rx_we_off[i])     rx_we_on[i] <=#Tp 1'h0;
      end
    end
    else
    begin
      always @ (posedge clk or posedge rst)
      begin
        if(rst)                   rx_we_on[i] <= 1'h0;
        else if(id_ok & rx_en[i]) rx_we_on[i] <=#Tp 1'h1;
        else if(rx_we_off[i])     rx_we_on[i] <=#Tp (|rx_we_off[i-1:0])? rx_we_on[i]: 1'h0;
      end
    end

  end //for

endgenerate

reg [127:0] rx_dt_ff;
always @ (posedge clk)
begin
  rx_dt_ff <=#Tp (rx_we)? rx_dt: rx_dt_ff;
  rx_en <=#Tp {rx_en[30:0],rx_we};
  rx_we_on_q <=#Tp rx_we_on;
end

always @ (posedge clk or posedge rst)
begin
  if(rst)               cnt <= 3'h0;
  else if(rx_en[0])     cnt <=#Tp 3'h1;
  else if(cnt == 0)     cnt <=#Tp 3'h0;
  else if(~|rx_we_on)   cnt <=#Tp 3'h0;
  else if(sample_point) cnt <=#Tp cnt+3'h1;
end

assign rx_we_ff = (reset_mode)? 32'h0: ~rx_we_on & rx_we_on_q;


always @ (posedge clk or posedge rst)
begin
  if(rst)                       timovr <= 1'h0;
  else if(rx_we)                timovr <=#Tp 1'h0;
  else if(~|cnt & sample_point) timovr <=#Tp 1'h1;
end

reg [127:0] rxdata [0:31];
reg [4:0] waddr;
always @ (*)
begin
       if(rx_we_ff[00]) waddr = 5'h00;
  else if(rx_we_ff[01]) waddr = 5'h01;
  else if(rx_we_ff[02]) waddr = 5'h02;
  else if(rx_we_ff[03]) waddr = 5'h03;
  else if(rx_we_ff[04]) waddr = 5'h04;
  else if(rx_we_ff[05]) waddr = 5'h05;
  else if(rx_we_ff[06]) waddr = 5'h06;
  else if(rx_we_ff[07]) waddr = 5'h07;
  else if(rx_we_ff[08]) waddr = 5'h08;
  else if(rx_we_ff[09]) waddr = 5'h09;
  else if(rx_we_ff[10]) waddr = 5'h0A;
  else if(rx_we_ff[11]) waddr = 5'h0B;
  else if(rx_we_ff[12]) waddr = 5'h0C;
  else if(rx_we_ff[13]) waddr = 5'h0D;
  else if(rx_we_ff[14]) waddr = 5'h0E;
  else if(rx_we_ff[15]) waddr = 5'h0F;
  else if(rx_we_ff[16]) waddr = 5'h10;
  else if(rx_we_ff[17]) waddr = 5'h11;
  else if(rx_we_ff[18]) waddr = 5'h12;
  else if(rx_we_ff[19]) waddr = 5'h13;
  else if(rx_we_ff[20]) waddr = 5'h14;
  else if(rx_we_ff[21]) waddr = 5'h15;
  else if(rx_we_ff[22]) waddr = 5'h16;
  else if(rx_we_ff[23]) waddr = 5'h17;
  else if(rx_we_ff[24]) waddr = 5'h18;
  else if(rx_we_ff[25]) waddr = 5'h19;
  else if(rx_we_ff[26]) waddr = 5'h1A;
  else if(rx_we_ff[27]) waddr = 5'h1B;
  else if(rx_we_ff[28]) waddr = 5'h1C;
  else if(rx_we_ff[29]) waddr = 5'h1D;
  else if(rx_we_ff[30]) waddr = 5'h1E;
  else if(rx_we_ff[31]) waddr = 5'h1F;
  else                  waddr = 5'h00;
end


integer j;
initial begin
  for(j=0;j<32;j=j+1) rxdata[j]=0;
end

always @ (posedge clk)
begin
  if(|rx_we_ff) rxdata[waddr] <=#Tp rx_dt_ff;
  rxmsgdata <=#Tp rxdata[rxdatawin];
end


endmodule
