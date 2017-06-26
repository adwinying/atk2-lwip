//////////////////////////////////////////////////////////////////////
////                                                              ////
////  can_registers.v                                             ////
////                                                              ////
////                                                              ////
////  This file is part of the CAN Protocol Controller            ////
////  http://www.opencores.org/projects/can/                      ////
////                                                              ////
////                                                              ////
////  Author(s):                                                  ////
////       Igor Mohor                                             ////
////       igorm@opencores.org                                    ////
////                                                              ////
////                                                              ////
////  All additional information is available in the README.txt   ////
////  file.                                                       ////
////                                                              ////
//////////////////////////////////////////////////////////////////////
////                                                              ////
//// Copyright (C) 2002, 2003 Authors                             ////
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
// CVS Revision History
//
// $Log: can_registers.v,v $
// Revision 1.35  2004/11/30 15:08:26  igorm
// irq is cleared after the release_buffer command. This bug was entered with
// changes for the edge triggered interrupts.
//
// Revision 1.34  2004/11/18 12:39:43  igorm
// Fixes for compatibility after the SW reset.
//
// Revision 1.33  2004/10/25 11:44:38  igorm
// Interrupt is always cleared for one clock after the irq register is read.
// This fixes problems when CPU is using IRQs that are edge triggered.
//
// Revision 1.32  2004/05/12 15:58:41  igorm
// Core improved to pass all tests with the Bosch VHDL Reference system.
//
// Revision 1.31  2003/09/25 18:55:49  mohor
// Synchronization changed, error counters fixed.
//
// Revision 1.30  2003/07/16 15:19:34  mohor
// Fixed according to the linter.
// Case statement for data_out joined.
//
// Revision 1.29  2003/07/10 01:59:04  tadejm
// Synchronization fixed. In some strange cases it didn't work according to
// the VHDL reference model.
//
// Revision 1.28  2003/07/07 11:21:37  mohor
// Little fixes (to fix warnings).
//
// Revision 1.27  2003/06/22 09:43:03  mohor
// synthesi full_case parallel_case fixed.
//
// Revision 1.26  2003/06/22 01:33:14  mohor
// clkout is clk/2 after the reset.
//
// Revision 1.25  2003/06/21 12:16:30  mohor
// paralel_case and full_case compiler directives added to case statements.
//
// Revision 1.24  2003/06/09 11:22:54  mohor
// data_out is already registered in the can_top.v file.
//
// Revision 1.23  2003/04/15 15:31:24  mohor
// Some features are supported in extended mode only (listen_only_mode...).
//
// Revision 1.22  2003/03/20 16:58:50  mohor
// unix.
//
// Revision 1.20  2003/03/11 16:31:05  mohor
// Mux used for clkout to avoid "gated clocks warning".
//
// Revision 1.19  2003/03/10 17:34:25  mohor
// Doubled declarations removed.
//
// Revision 1.18  2003/03/01 22:52:11  mohor
// Data is latched on read.
//
// Revision 1.17  2003/02/19 15:09:02  mohor
// Incomplete sensitivity list fixed.
//
// Revision 1.16  2003/02/19 14:44:03  mohor
// CAN core finished. Host interface added. Registers finished.
// Synchronization to the wishbone finished.
//
// Revision 1.15  2003/02/18 00:10:15  mohor
// Most of the registers added. Registers "arbitration lost capture", "error code
// capture" + few more still need to be added.
//
// Revision 1.14  2003/02/14 20:17:01  mohor
// Several registers added. Not finished, yet.
//
// Revision 1.13  2003/02/12 14:25:30  mohor
// abort_tx added.
//
// Revision 1.12  2003/02/11 00:56:06  mohor
// Wishbone interface added.
//
// Revision 1.11  2003/02/09 02:24:33  mohor
// Bosch license warning added. Error counters finished. Overload frames
// still need to be fixed.
//
// Revision 1.10  2003/01/31 01:13:38  mohor
// backup.
//
// Revision 1.9  2003/01/15 13:16:48  mohor
// When a frame with "remote request" is received, no data is stored
// to fifo, just the frame information (identifier, ...). Data length
// that is stored is the received data length and not the actual data
// length that is stored to fifo.
//
// Revision 1.8  2003/01/14 17:25:09  mohor
// Addresses corrected to decimal values (previously hex).
//
// Revision 1.7  2003/01/14 12:19:35  mohor
// rx_fifo is now working.
//
// Revision 1.6  2003/01/10 17:51:34  mohor
// Temporary version (backup).
//
// Revision 1.5  2003/01/09 14:46:58  mohor
// Temporary files (backup).
//
// Revision 1.4  2003/01/08 02:10:55  mohor
// Acceptance filter added.
//
// Revision 1.3  2002/12/27 00:12:52  mohor
// Header changed, testbench improved to send a frame (crc still missing).
//
// Revision 1.2  2002/12/26 16:00:34  mohor
// Testbench define file added. Clock divider register added.
//
// Revision 1.1.1.1  2002/12/20 16:39:21  mohor
// Initial
//
//
//

// synopsys translate_off
`include "timescale.v"
// synopsys translate_on
`include "can_defines.v"

module can_registers
( 
  clk,
  rst,
  cs,
  we,
  addr,
  data_in,
  data_out,
  irq_n,

  sample_point,
  transmitting,
  set_reset_mode,
  node_bus_off,
  error_status,
  rx_err_cnt,
  tx_err_cnt,
  transmit_status,
  receive_status,
  tx_successful,
  need_to_tx,
  overrun,
  info_empty,
  set_bus_error_irq,
  set_arbitration_lost_irq,
  arbitration_lost_capture,
  node_error_passive,
  node_error_active,
  rx_message_counter,


  /* Mode register */
  reset_mode,
  listen_only_mode,
  acceptance_filter_mode,
  self_test_mode,


  /* Command register */
  clear_data_overrun,
  release_buffer,
  abort_tx,
  tx_request,
  self_rx_request,
  single_shot_transmission,
  tx_state,
  tx_state_q,
  overload_request,
  overload_frame,

  /* Arbitration Lost Capture Register */
  read_arbitration_lost_capture_reg,

  /* Error Code Capture Register */
  read_error_code_capture_reg,
  error_capture_code,

  /* Bus Timing 0 register */
  baud_r_presc,
  sync_jump_width,

  /* Bus Timing 1 register */
  time_segment1,
  time_segment2,
  triple_sampling,
  
  /* Error Warning Limit register */
  error_warning_limit,

  /* Rx Error Counter register */
  we_rx_err_cnt,

  /* Tx Error Counter register */
  we_tx_err_cnt,

  /* Clock Divider register */
  extended_mode,
  clkout,
  
  
  /* This section is for BASIC and EXTENDED mode */
  /* Acceptance code register */
  acceptance_code_0,

  /* Acceptance mask register */
  acceptance_mask_0,
  /* End: This section is for BASIC and EXTENDED mode */
  
  /* This section is for EXTENDED mode */
  /* Acceptance code register */
  acceptance_code_1,
  acceptance_code_2,
  acceptance_code_3,

  /* Acceptance mask register */
  acceptance_mask_1,
  acceptance_mask_2,
  acceptance_mask_3,
  /* End: This section is for EXTENDED mode */
  
  rx_dt,
  rx_we,
  /* Tx data registers. Holding identifier (basic mode), tx frame information (extended mode) and data */
  tx_data_0,
  tx_data_1,
  tx_data_2,
  tx_data_3,
  tx_data_4,
  tx_data_5,
  tx_data_6,
  tx_data_7,
  tx_data_8,
  tx_data_9,
  tx_data_10,
  tx_data_11,
  tx_data_12
  /* End: Tx data registers */
  
  


);

parameter Tp = 1;

input         clk;
input         rst;
input         cs;
input         we;
input   [9:0] addr;
input  [31:0] data_in;

output [31:0] data_out;
reg    [31:0] data_out;

output        irq_n;

input         sample_point;
input         transmitting;
input         set_reset_mode;
input         node_bus_off;
input         error_status;
input   [7:0] rx_err_cnt;
input   [7:0] tx_err_cnt;
input         transmit_status;
input         receive_status;
input         tx_successful;
input         need_to_tx;
input         overrun;
input         info_empty;
input         set_bus_error_irq;
input         set_arbitration_lost_irq;
input   [4:0] arbitration_lost_capture;
input         node_error_passive;
input         node_error_active;
input   [6:0] rx_message_counter;



/* Mode register */
output        reset_mode;
output        listen_only_mode;
output        acceptance_filter_mode;
output        self_test_mode;

/* Command register */
output        clear_data_overrun;
output        release_buffer;
output        abort_tx;
output        tx_request;
output        self_rx_request;
output        single_shot_transmission;
input         tx_state;
input         tx_state_q;
output        overload_request;
input         overload_frame;


/* Arbitration Lost Capture Register */
output        read_arbitration_lost_capture_reg;

/* Error Code Capture Register */
output        read_error_code_capture_reg;
input   [7:0] error_capture_code;

/* Bus Timing 0 register */
output  [5:0] baud_r_presc;
output  [1:0] sync_jump_width;


/* Bus Timing 1 register */
output  [3:0] time_segment1;
output  [2:0] time_segment2;
output        triple_sampling;

/* Error Warning Limit register */
output  [7:0] error_warning_limit;

/* Rx Error Counter register */
output        we_rx_err_cnt;

/* Tx Error Counter register */
output        we_tx_err_cnt;

/* Clock Divider register */
output        extended_mode;
output        clkout;


/* This section is for BASIC and EXTENDED mode */
/* Acceptance code register */
output  [7:0] acceptance_code_0;

/* Acceptance mask register */
output  [7:0] acceptance_mask_0;

/* End: This section is for BASIC and EXTENDED mode */


/* This section is for EXTENDED mode */
/* Acceptance code register */
output  [7:0] acceptance_code_1;
output  [7:0] acceptance_code_2;
output  [7:0] acceptance_code_3;

/* Acceptance mask register */
output  [7:0] acceptance_mask_1;
output  [7:0] acceptance_mask_2;
output  [7:0] acceptance_mask_3;

/* End: This section is for EXTENDED mode */


input [127:0] rx_dt;
input         rx_we;
/* Tx data registers. Holding identifier (basic mode), tx frame information (extended mode) and data */
output  [7:0] tx_data_0;
output  [7:0] tx_data_1;
output  [7:0] tx_data_2;
output  [7:0] tx_data_3;
output  [7:0] tx_data_4;
output  [7:0] tx_data_5;
output  [7:0] tx_data_6;
output  [7:0] tx_data_7;
output  [7:0] tx_data_8;
output  [7:0] tx_data_9;
output  [7:0] tx_data_10;
output  [7:0] tx_data_11;
output  [7:0] tx_data_12;
/* End: Tx data registers */


reg  [15:0]   transmit_cancel;
reg  [31:0]   rxovrwrite;
reg           tx_successful_q;
reg           overrun_q;
reg           overrun_status;
reg           transmission_complete;
reg           transmit_buffer_status_q;
reg           receive_buffer_status;
reg           error_status_q;
reg           node_bus_off_q;
reg           node_error_passive_q;
reg           transmit_buffer_status;
reg           single_shot_transmission;
reg           self_rx_request;
reg           irq_n;

// Some interrupts exist in basic mode and in extended mode. Since they are in different registers they need to be multiplexed.
wire          data_overrun_irq_en;
wire          error_warning_irq_en;
wire          transmit_irq_en;
wire          receive_irq_en;

wire    [7:0] irq_reg;
wire          irq;

reg   [15:0] txreq;
reg   [15:0] txabort;
reg   [15:0] txcmp;
reg   [31:0] rxwait;
reg   [31:0] rxcmp;
reg   [15:0] rxselfreq;

// fsm
reg [1:0] state;
reg [2:0] st_sel_cnt;
parameter st_idle = 2'h0;
parameter st_sel  = 2'h1;
parameter st_set  = 2'h2;
parameter st_wait = 2'h3;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    state <= st_idle;
  else if (reset_mode)
    state <=#Tp st_idle;
  else case (state)
    st_idle : if (|(txreq & ~txabort)) state <=#Tp st_sel;
    st_sel  : if (&st_sel_cnt)         state <=#Tp st_set;
    st_set  : if ( need_to_tx)         state <=#Tp st_wait;
    st_wait : if (~need_to_tx)         state <=#Tp st_idle;
  endcase
end
always @ (posedge clk or posedge rst)
begin
  if (rst)
    st_sel_cnt <= 3'h0;
  else if (state == st_sel)
    st_sel_cnt <=#Tp st_sel_cnt +3'h1;
  else
    st_sel_cnt <=#Tp 3'h0;
end



// sort tx data
wire [127:0] txdata [0:15];
reg [127:0] txtmp  ;
reg [28:0]  txid   ;
reg         txfmt  ;
reg         txrtr  ;
reg [3:0]   txdlc  ;
reg [7:0]   txdata1;
reg [7:0]   txdata2;
reg [7:0]   txdata3;
reg [7:0]   txdata4;
reg [7:0]   txdata5;
reg [7:0]   txdata6;
reg [7:0]   txdata7;
reg [7:0]   txdata8;
reg [3:0]   txmsgbox;
wire        rxselfreq_en = rxselfreq[txmsgbox];

always @ (*)
begin
  txtmp   = txdata[txmsgbox];
  txfmt   = txtmp[0*32+31];
  txid    = txtmp[0*32+28:0*32];
  txrtr   = txtmp[1*32+4];
  txdlc   = txtmp[1*32+3:1*32];
  txdata1 = txtmp[2*32+0*8+7:2*32+0*8];
  txdata2 = txtmp[2*32+1*8+7:2*32+1*8];
  txdata3 = txtmp[2*32+2*8+7:2*32+2*8];
  txdata4 = txtmp[2*32+3*8+7:2*32+3*8];
  txdata5 = txtmp[3*32+0*8+7:3*32+0*8];
  txdata6 = txtmp[3*32+1*8+7:3*32+1*8];
  txdata7 = txtmp[3*32+2*8+7:3*32+2*8];
  txdata8 = txtmp[3*32+3*8+7:3*32+3*8];
end


// latch tx data
wire we_txstart;
reg  [7:0] tx_data_0;
reg  [7:0] tx_data_1;
reg  [7:0] tx_data_2;
reg  [7:0] tx_data_3;
reg  [7:0] tx_data_4;
reg  [7:0] tx_data_5;
reg  [7:0] tx_data_6;
reg  [7:0] tx_data_7;
reg  [7:0] tx_data_8;
reg  [7:0] tx_data_9;
reg  [7:0] tx_data_10;
reg  [7:0] tx_data_11;
reg  [7:0] tx_data_12;
always @ (posedge clk or posedge rst)
begin
  if (rst)
  begin
    tx_data_0  <= 8'h0;
    tx_data_1  <= 8'h0;
    tx_data_2  <= 8'h0;
    tx_data_3  <= 8'h0;
    tx_data_4  <= 8'h0;
    tx_data_5  <= 8'h0;
    tx_data_6  <= 8'h0;
    tx_data_7  <= 8'h0;
    tx_data_8  <= 8'h0;
    tx_data_9  <= 8'h0;
    tx_data_10 <= 8'h0;
    tx_data_11 <= 8'h0;
    tx_data_12 <= 8'h0;
  end
  else if (we_txstart)
  begin
    if(~extended_mode)
    begin
      tx_data_0  <=#Tp txid[28:21];
      tx_data_1  <=#Tp {txid[20:18],txrtr,txdlc};
      tx_data_2  <=#Tp txdata1;
      tx_data_3  <=#Tp txdata2;
      tx_data_4  <=#Tp txdata3;
      tx_data_5  <=#Tp txdata4;
      tx_data_6  <=#Tp txdata5;
      tx_data_7  <=#Tp txdata6;
      tx_data_8  <=#Tp txdata7;
      tx_data_9  <=#Tp txdata8;
      tx_data_10 <=#Tp 8'h0;
      tx_data_11 <=#Tp 8'h0;
      tx_data_12 <=#Tp 8'h0;
    end
    else
    begin
      tx_data_0  <=#Tp {txfmt,txrtr,2'h0,txdlc};
      tx_data_1  <=#Tp txid[28:21];
      tx_data_2  <=#Tp (~txfmt)? {txid[20:18],5'h0}: txid[20:13];
      tx_data_3  <=#Tp (~txfmt)? txdata1: txid[12:5];
      tx_data_4  <=#Tp (~txfmt)? txdata2: {txid[4:0],3'h0};
      tx_data_5  <=#Tp (~txfmt)? txdata3: txdata1;
      tx_data_6  <=#Tp (~txfmt)? txdata4: txdata2;
      tx_data_7  <=#Tp (~txfmt)? txdata5: txdata3;
      tx_data_8  <=#Tp (~txfmt)? txdata6: txdata4;
      tx_data_9  <=#Tp (~txfmt)? txdata7: txdata5;
      tx_data_10 <=#Tp (~txfmt)? txdata8: txdata6;
      tx_data_11 <=#Tp                    txdata7;
      tx_data_12 <=#Tp                    txdata8;
    end
  end
end


// arbitration lost
reg [3:0] arbitration_lost_capture_mbox;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    arbitration_lost_capture_mbox <= 4'h0;
  else if (set_arbitration_lost_irq)
    arbitration_lost_capture_mbox <=#Tp txmsgbox;
end

// error capture
reg set_bus_error_irq_q;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    set_bus_error_irq_q <= 1'h0;
  else
    set_bus_error_irq_q <=#Tp set_bus_error_irq;
end

reg [3:0] error_capture_code_mbox;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    error_capture_code_mbox <= 4'h0;
  else if(set_bus_error_irq_q)
    error_capture_code_mbox <=#Tp (error_capture_code[5])? 4'h0: txmsgbox;//0:tx error 1:rx error
end


wire we_mode                  = cs & we & (addr == 10'h0);
wire we_command               = 0;
wire we_bus_timing_0          = cs & we & (addr == 10'h034) & reset_mode;
wire we_bus_timing_1          = cs & we & (addr == 10'h034) & reset_mode;
wire we_clock_divider_low     = cs & we & (addr == 10'h034);
wire we_clock_divider_hi      = we_clock_divider_low & reset_mode;

wire we_txreq    = cs & we & (addr == 10'h004);
wire we_txabort  = cs & we & (addr == 10'h008);
wire we_txcmp    = cs & we & (addr == 10'h00C);
wire we_txcancel = cs & we & (addr == 10'h010);
wire we_rxwait   = cs & we & (addr == 10'h014);
wire we_rxcmp    = cs & we & (addr == 10'h018);
wire we_rxselfreq= cs & we & (addr == 10'h020);


wire read = cs & (~we);
wire read_rxovrwrite = read & (addr == 10'h01C);
wire read_irq_reg = read & (addr == 10'h028);
assign read_arbitration_lost_capture_reg = read & extended_mode & (addr == 10'h040);
assign read_error_code_capture_reg = read & extended_mode & (addr == 10'h044);

/* This section is for BASIC and EXTENDED mode */
wire we_acceptance_code_0       = cs & we &   reset_mode  & (addr == 10'h038);
wire we_acceptance_mask_0       = cs & we &   reset_mode  & (addr == 10'h03C);
wire we_datawin                 = cs & we & (addr == 10'h04C);
assign we_txstart               = (state == st_set) & transmit_buffer_status;
/* End: This section is for BASIC and EXTENDED mode */


/* This section is for EXTENDED mode */
wire   we_interrupt_enable      = cs & we & (addr == 10'h02C) ;
wire   we_irq_rxen              = cs & we & (addr == 10'h030) ;
wire   we_error_warning_limit   = cs & we & (addr == 10'h048) & reset_mode ;
assign we_rx_err_cnt            = cs & we & (addr == 10'h048) & reset_mode ;
assign we_tx_err_cnt            = cs & we & (addr == 10'h048) & reset_mode ;
wire   we_acceptance_code_1     = cs & we & (addr == 10'h038) & reset_mode ;
wire   we_acceptance_code_2     = cs & we & (addr == 10'h038) & reset_mode ;
wire   we_acceptance_code_3     = cs & we & (addr == 10'h038) & reset_mode ;
wire   we_acceptance_mask_1     = cs & we & (addr == 10'h03C) & reset_mode ;
wire   we_acceptance_mask_2     = cs & we & (addr == 10'h03C) & reset_mode ;
wire   we_acceptance_mask_3     = cs & we & (addr == 10'h03C) & reset_mode ;
/* End: This section is for EXTENDED mode */



always @ (posedge clk)
begin
  tx_successful_q           <=#Tp tx_successful;
  overrun_q                 <=#Tp overrun;
  transmit_buffer_status_q  <=#Tp transmit_buffer_status;
  error_status_q            <=#Tp error_status;
  node_bus_off_q            <=#Tp node_bus_off;
  node_error_passive_q      <=#Tp node_error_passive;
end



/* Mode register */
wire   [0:0] mode;
wire   [4:1] mode_basic;
wire   [3:1] mode_ext;
wire         receive_irq_en_basic;
wire         transmit_irq_en_basic;
wire         error_irq_en_basic;
wire         overrun_irq_en_basic;

can_register_asyn_syn #(1, 1'h1) MODE_REG0
( .data_in(data_in[0]),
  .data_out(mode[0]),
  .we(we_mode),
  .clk(clk),
  .rst(rst),
  .rst_sync(set_reset_mode)
);

can_register_asyn #(4, 4'h0) MODE_REG_BASIC
( .data_in(data_in[4:1]),
  .data_out(mode_basic[4:1]),
  .we(we_mode),
  .clk(clk),
  .rst(rst)
);

can_register_asyn #(3, 3'h0) MODE_REG_EXT
( .data_in(data_in[3:1]),
  .data_out(mode_ext[3:1]),
  .we(we_mode & reset_mode),
  .clk(clk),
  .rst(rst)
);

assign reset_mode             = mode[0];
assign listen_only_mode       = extended_mode & mode_ext[1];
assign self_test_mode         = extended_mode & mode_ext[2];
assign acceptance_filter_mode = extended_mode & mode_ext[3];

assign receive_irq_en_basic  = mode_basic[1];
assign transmit_irq_en_basic = mode_basic[2];
assign error_irq_en_basic    = mode_basic[3];
assign overrun_irq_en_basic  = mode_basic[4];
/* End Mode register */


/* Command register */
wire   [4:0] command;
can_register_asyn_syn #(1, 1'h0) COMMAND_REG0
( .data_in(~rxselfreq_en),
  .data_out(command[0]),
  .we(we_txstart),
  .clk(clk),
  .rst(rst),
  .rst_sync(command[0] & sample_point | reset_mode)
);

can_register_asyn_syn #(1, 1'h0) COMMAND_REG1
( .data_in(1'h1),
  .data_out(command[1]),
  .we(we_txstart),
  .clk(clk),
  .rst(rst),
  .rst_sync(sample_point & (tx_request | (abort_tx & ~transmitting)) | reset_mode)
);

can_register_asyn_syn #(2, 2'h0) COMMAND_REG
( .data_in(data_in[3:2]),
  .data_out(command[3:2]),
  .we(we_command),
  .clk(clk),
  .rst(rst),
  .rst_sync(|command[3:2] | reset_mode)
);

can_register_asyn_syn #(1, 1'h0) COMMAND_REG4
( .data_in(rxselfreq_en),
  .data_out(command[4]),
  .we(we_txstart),
  .clk(clk),
  .rst(rst),
  .rst_sync(command[4] & sample_point | reset_mode)
);


always @ (posedge clk or posedge rst)
begin
  if (rst)
    self_rx_request <= 1'b0;
  else if (command[4] & (~command[0]))
    self_rx_request <=#Tp 1'b1;
  else if ((~tx_state) & tx_state_q)
    self_rx_request <=#Tp 1'b0;
end


assign clear_data_overrun = command[3];
assign release_buffer = command[2];
assign tx_request = command[0] | command[4];
assign abort_tx = (state == st_wait) & txabort[txmsgbox] & (~tx_request);//command[1] & (~tx_request);


always @ (posedge clk or posedge rst)
begin
  if (rst)
    single_shot_transmission <= 1'b0;
//  else if (tx_request & command[1] & sample_point)
    else if (tx_request & sample_point)
    single_shot_transmission <=#Tp 1'b1;
//else if ((~tx_state) & tx_state_q)
else if ((~tx_state) & tx_state_q | (abort_tx & (~transmitting)))
    single_shot_transmission <=#Tp 1'b0;
end


/*
can_register_asyn_syn #(1, 1'h0) COMMAND_REG_OVERLOAD  // Uncomment this to enable overload requests !!!
( .data_in(data_in[5]),
  .data_out(overload_request),
  .we(we_command),
  .clk(clk),
  .rst(rst),
  .rst_sync(overload_frame & ~overload_frame_q)
);

reg           overload_frame_q;

always @ (posedge clk or posedge rst)
begin
  if (rst)
    overload_frame_q <= 1'b0;
  else
    overload_frame_q <=#Tp overload_frame;
end
*/
assign overload_request = 0;  // Overload requests are not supported, yet !!!





/* End Command register */


/* Status register */

wire   [7:0] status;

assign status[7] = node_bus_off;
assign status[6] = error_status;
assign status[5] = transmit_status;
assign status[4] = receive_status;
assign status[3] = transmission_complete;
assign status[2] = transmit_buffer_status;
assign status[1] = overrun_status;
assign status[0] = receive_buffer_status;



always @ (posedge clk or posedge rst)
begin
  if (rst)
    transmission_complete <= 1'b1;
  else if (tx_successful & (~tx_successful_q) | abort_tx)
    transmission_complete <=#Tp 1'b1;
  else if (tx_request)
    transmission_complete <=#Tp 1'b0;
end


always @ (posedge clk or posedge rst)
begin
  if (rst)
    transmit_buffer_status <= 1'b1;
  else if (tx_request)
    transmit_buffer_status <=#Tp 1'b0;
  else if (reset_mode || !need_to_tx)
    transmit_buffer_status <=#Tp 1'b1;
end


always @ (posedge clk or posedge rst)
begin
  if (rst)
    overrun_status <= 1'b0;
  else if (overrun & (~overrun_q))
    overrun_status <=#Tp 1'b1;
  else if (reset_mode || clear_data_overrun)
    overrun_status <=#Tp 1'b0;
end


always @ (posedge clk or posedge rst)
begin
  if (rst)
    receive_buffer_status <= 1'b0;
  else if (reset_mode || release_buffer)
    receive_buffer_status <=#Tp 1'b0;
  else if (~info_empty)
    receive_buffer_status <=#Tp 1'b1;
end

/* End Status register */


/* Interrupt Enable register (extended mode) */
wire   [7:0] irq_en_ext;
wire  [31:0] irq_rxen;
wire         bus_error_irq_en;
wire         arbitration_lost_irq_en;
wire         error_passive_irq_en;
wire         transmit_cancel_irq_en;
wire         data_overrun_irq_en_ext;
wire         error_warning_irq_en_ext;
wire         transmit_irq_en_ext;
wire         receive_irq_en_ext;

can_register_asyn #(8, 8'h0) IRQ_EN_REG
( .data_in(data_in[7:0]),
  .data_out(irq_en_ext),
  .we(we_interrupt_enable),
  .clk(clk),
  .rst(rst)
);

can_register_asyn #(32, 32'h0) IRQ_RXEN_REG
( .data_in(data_in),
  .data_out(irq_rxen),
  .we(we_irq_rxen),
  .clk(clk),
  .rst(rst)
);


assign bus_error_irq_en             = extended_mode & irq_en_ext[7];
assign arbitration_lost_irq_en      = extended_mode & irq_en_ext[6];
assign error_passive_irq_en         = extended_mode & irq_en_ext[5];
assign transmit_cancel_irq_en       = irq_en_ext[4];
assign data_overrun_irq_en_ext      = irq_en_ext[3];
assign error_warning_irq_en_ext     = irq_en_ext[2];
assign transmit_irq_en_ext          = irq_en_ext[1];
assign receive_irq_en_ext           = irq_en_ext[0];
/* End Bus Timing 0 register */


/* Bus Timing 0 register */
wire   [7:0] bus_timing_0;
can_register_asyn #(8, 8'h0) BUS_TIMING_0_REG
( .data_in(data_in[0*8+7:0*8]),
  .data_out(bus_timing_0),
  .we(we_bus_timing_0),
  .clk(clk),
  .rst(rst)
);

assign baud_r_presc = bus_timing_0[5:0];
assign sync_jump_width = bus_timing_0[7:6];
/* End Bus Timing 0 register */


/* Bus Timing 1 register */
wire   [7:0] bus_timing_1;
can_register_asyn #(8, 8'h0) BUS_TIMING_1_REG
( .data_in(data_in[1*8+7:1*8]),
  .data_out(bus_timing_1),
  .we(we_bus_timing_1),
  .clk(clk),
  .rst(rst)
);

assign time_segment1 = bus_timing_1[3:0];
assign time_segment2 = bus_timing_1[6:4];
assign triple_sampling = bus_timing_1[7];
/* End Bus Timing 1 register */


/* Error Warning Limit register */
can_register_asyn #(8, 8'd96) ERROR_WARNING_REG
( .data_in(data_in[0*8+7:0*8]),
  .data_out(error_warning_limit),
  .we(we_error_warning_limit),
  .clk(clk),
  .rst(rst)
);
/* End Error Warning Limit register */



/* Clock Divider register */
wire   [7:0] clock_divider;
wire         clock_off;
wire   [2:0] cd;
reg    [2:0] clkout_div;
reg    [2:0] clkout_cnt;
reg          clkout_tmp;

can_register_asyn #(1, 1'h0) CLOCK_DIVIDER_REG_7
( .data_in(data_in[3*8+7]),
  .data_out(clock_divider[7]),
  .we(we_clock_divider_hi),
  .clk(clk),
  .rst(rst)
);

assign clock_divider[6:4] = 3'h0;

can_register_asyn #(1, 1'h0) CLOCK_DIVIDER_REG_3
( .data_in(data_in[3*8+3]),
  .data_out(clock_divider[3]),
  .we(we_clock_divider_hi),
  .clk(clk),
  .rst(rst)
);

can_register_asyn #(3, 3'h0) CLOCK_DIVIDER_REG_LOW
( .data_in(data_in[3*8+2:3*8]),
  .data_out(clock_divider[2:0]),
  .we(we_clock_divider_low),
  .clk(clk),
  .rst(rst)
);

assign extended_mode = clock_divider[7];
assign clock_off     = clock_divider[3];
assign cd[2:0]       = clock_divider[2:0];



always @ (cd)
begin
  case (cd)                       /* synthesis full_case parallel_case */ 
    3'b000 : clkout_div = 3'd0;
    3'b001 : clkout_div = 3'd1;
    3'b010 : clkout_div = 3'd2;
    3'b011 : clkout_div = 3'd3;
    3'b100 : clkout_div = 3'd4;
    3'b101 : clkout_div = 3'd5;
    3'b110 : clkout_div = 3'd6;
    3'b111 : clkout_div = 3'd0;
  endcase
end



always @ (posedge clk or posedge rst)
begin
  if (rst)
    clkout_cnt <= 3'h0;
  else if (clkout_cnt == clkout_div)
    clkout_cnt <=#Tp 3'h0;
  else
    clkout_cnt <= clkout_cnt + 1'b1;
end



always @ (posedge clk or posedge rst)
begin
  if (rst)
    clkout_tmp <= 1'b0;
  else if (clkout_cnt == clkout_div)
    clkout_tmp <=#Tp ~clkout_tmp;
end


assign clkout = clock_off ? 1'b1 : ((&cd)? clk : clkout_tmp);



/* End Clock Divider register */




/* This section is for BASIC and EXTENDED mode */

/* Acceptance code register */
can_register_asyn #(8, 8'h0) ACCEPTANCE_CODE_REG0
( .data_in(data_in[3*8+7:3*8]),
  .data_out(acceptance_code_0),
  .we(we_acceptance_code_0),
  .clk(clk),
  .rst(rst)
);
/* End: Acceptance code register */


/* Acceptance mask register */
can_register_asyn #(8, 8'h0) ACCEPTANCE_MASK_REG0
( .data_in(data_in[3*8+7:3*8]),
  .data_out(acceptance_mask_0),
  .we(we_acceptance_mask_0),
  .clk(clk),
  .rst(rst)
);
/* End: Acceptance mask register */


/* Data window register */
wire [4:0] rxdatawin;
can_register_asyn #(5, 5'h0) MODE_RXDATAWIN_REG
( .data_in(data_in[20:16]),
  .data_out(rxdatawin),
  .we(we_datawin),
  .clk(clk),
  .rst(rst)
);
/* End: Data window register */
/* End: This section is for BASIC and EXTENDED mode */


/* Tx data register. */
parameter t = 16;
wire [63:0] we_txdata;
wire [2047:0] txdata_reg;
wire [16*29+28:0] txdata_reg_id;
reg [16*34-1:0] txdata_ff;
reg [ 8*34-1:0] rank_lvl1;
reg [ 4*34-1:0] rank_lvl2;
reg [ 2*34-1:0] rank_lvl3;
wire [63:0] mboxnum;

reg aleb1[7:0];
reg aleb2[3:0];
reg aleb3[1:0];
reg aleb4;

assign mboxnum = 64'hfedcba9876543210;
generate
  genvar i,j;
  for (i=0; i<16; i=i+1) begin :txdata_i_reg
    for (j=0; j<4; j=j+1) begin :txdata_j_reg
      assign we_txdata[i*4+j] = cs & we & ~txreq[i] & (addr[9:8] == 2'h1) & (addr[7:4] == i) & (addr[3:0] == (4'h4*j));
      can_register_asyn #(32, 32'h0) TXDATA_REG( .data_in(data_in),  .data_out(txdata_reg[i*128+j*32+31:i*128+j*32]),  .we(we_txdata[i*4+j]),  .clk(clk),  .rst(rst));
    end //for
    assign txdata[i] = txdata_reg[i*128+127:i*128];



  // arbiter
    assign txdata_reg_id[i*29+28:i*29] = (extended_mode & txdata_reg[i*128+31])? txdata_reg[i*128+28:i*128]: {txdata_reg[i*128+28:i*128+18],18'h0};

    always @ (posedge clk or posedge rst)
    begin
      if (rst)
        txdata_ff[i*34+33:i*34] <= 34'h0;
      else if (~reset_mode & (state == st_idle) & |(txreq & ~txabort))
        txdata_ff[i*34+33:i*34] <=#Tp {txreq[i] & ~txabort[i] , mboxnum[i*4+3:i*4] , txdata_reg_id[i*29+28:i*29]};
    end

    if(i<8)begin


always @ (posedge clk) aleb1[i] <= (txdata_ff[2*i*34+28:2*i*34]<=txdata_ff[(2*i+1)*34+28:(2*i+1)*34]);

    begin
      always @ (posedge clk or posedge rst)
      begin
        case({txdata_ff[(2*i+1)*34+33],txdata_ff[2*i*34+33]})
          2'h0: rank_lvl1[i*34+33:i*34] <=#Tp txdata_ff[2*i*34+33:2*i*34];
          2'h1: rank_lvl1[i*34+33:i*34] <=#Tp txdata_ff[2*i*34+33:2*i*34];
          2'h2: rank_lvl1[i*34+33:i*34] <=#Tp txdata_ff[(2*i+1)*34+33:(2*i+1)*34];
          2'h3: rank_lvl1[i*34+33:i*34] <=#Tp (aleb1[i])? txdata_ff[2*i*34+33:2*i*34]: txdata_ff[(2*i+1)*34+33:(2*i+1)*34];
          //(txdata_ff[2*i*34+28:2*i*34]<=txdata_ff[(2*i+1)*34+28:(2*i+1)*34])? txdata_ff[2*i*34+33:2*i*34]: txdata_ff[(2*i+1)*34+33:(2*i+1)*34];
        endcase
      end
    end
end
    if(i<4)begin

always @ (posedge clk) aleb2[i] <= (rank_lvl1[2*i*34+28:2*i*34]<=rank_lvl1[(2*i+1)*34+28:(2*i+1)*34]);

    begin
      always @ (posedge clk or posedge rst)
      begin
        case({rank_lvl1[(2*i+1)*34+33],rank_lvl1[2*i*34+33]})
          2'h0: rank_lvl2[i*34+33:i*34] <=#Tp rank_lvl1[2*i*34+33:2*i*34];
          2'h1: rank_lvl2[i*34+33:i*34] <=#Tp rank_lvl1[2*i*34+33:2*i*34];
          2'h2: rank_lvl2[i*34+33:i*34] <=#Tp rank_lvl1[(2*i+1)*34+33:(2*i+1)*34];
          2'h3: rank_lvl2[i*34+33:i*34] <=#Tp (aleb2[i])? rank_lvl1[2*i*34+33:2*i*34]: rank_lvl1[(2*i+1)*34+33:(2*i+1)*34];//rank_lvl1[(2*i+1)*34+33:(2*i+1)*34];
          //(rank_lvl1[2*i*34+28:2*i*34]<=rank_lvl1[(2*i+1)*34+28:(2*i+1)*34])? rank_lvl1[2*i*34+33:2*i*34]: rank_lvl1[(2*i+1)*34+33:(2*i+1)*34];
        endcase
      end
    end
end
    if(i<2)
    begin

always @ (posedge clk) aleb3[i] <= (rank_lvl2[2*i*34+28:2*i*34]<=rank_lvl2[(2*i+1)*34+28:(2*i+1)*34]);


      always @ (posedge clk or posedge rst)
      begin
        case({rank_lvl2[(2*i+1)*34+33],rank_lvl2[2*i*34+33]})
          2'h0: rank_lvl3[i*34+33:i*34] <=#Tp rank_lvl2[2*i*34+33:2*i*34];
          2'h1: rank_lvl3[i*34+33:i*34] <=#Tp rank_lvl2[2*i*34+33:2*i*34];
          2'h2: rank_lvl3[i*34+33:i*34] <=#Tp rank_lvl2[(2*i+1)*34+33:(2*i+1)*34];
          2'h3: rank_lvl3[i*34+33:i*34] <=#Tp (aleb3[i])? rank_lvl2[2*i*34+33:2*i*34]: rank_lvl2[(2*i+1)*34+33:(2*i+1)*34];//rank_lvl2[(2*i+1)*34+33:(2*i+1)*34];
          //(rank_lvl2[2*i*34+28:2*i*34]<=rank_lvl2[(2*i+1)*34+28:(2*i+1)*34])? rank_lvl2[2*i*34+33:2*i*34]: rank_lvl2[(2*i+1)*34+33:(2*i+1)*34];
        endcase
      end
    end


    if(i<1)
    begin

always @ (posedge clk) aleb4 <= (rank_lvl3[2*i*34+28:2*i*34]<=rank_lvl3[(2*i+1)*34+28:(2*i+1)*34]);


      always @ (posedge clk or posedge rst)
      begin
        case({rank_lvl3[(2*i+1)*34+33],rank_lvl3[2*i*34+33]})
          2'h0: txmsgbox <=#Tp rank_lvl3[2*i*34+32:2*i*34+29];
          2'h1: txmsgbox <=#Tp rank_lvl3[2*i*34+32:2*i*34+29];
          2'h2: txmsgbox <=#Tp rank_lvl3[(2*i+1)*34+32:(2*i+1)*34+29];
          2'h3: txmsgbox <=#Tp (aleb4)? rank_lvl3[2*i*34+32:2*i*34+29]: rank_lvl3[(2*i+1)*34+32:(2*i+1)*34+29];//rank_lvl3[(2*i+1)*34+32:(2*i+1)*34+29];
          //(rank_lvl3[2*i*34+28:2*i*34]<=rank_lvl3[(2*i+1)*34+28:(2*i+1)*34])? rank_lvl3[2*i*34+32:2*i*34+29]: rank_lvl3[(2*i+1)*34+32:(2*i+1)*34+29];
        endcase
      end
    end


  end //for
endgenerate
/* End: Tx data register. */


/* Rx data register. */
parameter r = 32;
wire [31:0] rx_we_ff;
wire [127:0] rxdata [0:31];
wire [31:0] we_rxcode;
wire [31:0] we_rxmask;
wire [31:0] rxmask [0:31];
wire [31:0] rxcode [0:31];
wire [1023:0] rxmask_in;
wire [1023:0] rxcode_in;
generate
  genvar k;
  for (k=0; k<32; k=k+1) begin :rxdata_reg
//  can_register_asyn #(128, 128'h0) RXWRDATA_REG0( .data_in(rx_dt_ff),  .data_out(rxdata[k]),  .we(rx_we_ff[k]),  .clk(clk),  .rst(rst));

    assign we_rxcode[k] = cs & we & (addr == 10'h070) & (rxdatawin == k) & reset_mode;
    assign we_rxmask[k] = cs & we & (addr == 10'h074) & (rxdatawin == k) & reset_mode;

    can_register_asyn #(32, 32'h0) RXWRDATA_REG2( .data_in(data_in),  .data_out(rxcode[k]),  .we(we_rxcode[k]),  .clk(clk),  .rst(rst));
    can_register_asyn #(32, 32'h0) RXWRDATA_REG3( .data_in(data_in),  .data_out(rxmask[k]),  .we(we_rxmask[k]),  .clk(clk),  .rst(rst));

    assign rxmask_in[32*k+31:32*k] = rxmask[k];
    assign rxcode_in[32*k+31:32*k] = rxcode[k];

  end //for
endgenerate

wire [127:0] rxmsgdata;
can_rxmboxacf can_rxmboxacf(
  .clk(clk),
  .rst(rst),
  .sample_point(sample_point),
  .rxwait(rxwait),
  .rxcmp(rxcmp),
  .reset_mode(reset_mode),
  .acceptance_filter_mode(acceptance_filter_mode),
  .extended_mode(extended_mode),
  .rxcode(rxcode_in),
  .rxmask(rxmask_in),
  .rxdatawin(addr[8:4]),
  .rx_dt(rx_dt),
  .rx_we(rx_we),
  .rxmsgdata(rxmsgdata),
  .rx_we_ff(rx_we_ff)
);
/* End: Rx data register. */


/* Tx controll register. */
generate
  genvar a;
  for (a=0; a<16; a=a+1) begin :txsts_reg
    
    
    always @ (posedge clk or posedge rst)
    begin
      if (rst)
        txreq[a] <= 1'h0;
      else if (reset_mode)
        txreq[a] <=#Tp 1'h0;
      else if (we_txreq & data_in[a] & ~txreq[a])
        txreq[a] <=#Tp 1'h1;
      else if ((state == st_wait) & (txmsgbox == a) & tx_successful & (~tx_successful_q))
        txreq[a] <=#Tp 1'h0;
      else if (txabort[a])
        case(state)
          st_idle :                    txreq[a] <=#Tp 1'h0;
          st_sel  :                    txreq[a] <=#Tp txreq[a];
          default : if (txmsgbox != a) txreq[a] <=#Tp 1'h0;
        endcase
    end
    
    
    always @ (posedge clk or posedge rst)
    begin
      if (rst)
        txabort[a] <= 1'h0;
      else if (reset_mode)
        txabort[a] <=#Tp 1'h0;
      else if (~txreq[a])
        txabort[a] <=#Tp 1'h0;
      else if (we_txabort & data_in[a] & txreq[a])
        txabort[a] <=#Tp 1'h1;
    end
    
    
    always @ (posedge clk or posedge rst)
    begin
      if (rst)
        transmit_cancel[a] <= 1'h0;
      else if (txreq[a] & txabort[a])
        case(state)
          st_idle :                    transmit_cancel[a] <=#Tp 1'h1;
          st_sel  :                    transmit_cancel[a] <=#Tp transmit_cancel[a];
          default : if (txmsgbox != a) transmit_cancel[a] <=#Tp 1'h1;
        endcase
      else if (we_txcancel & data_in[a])
        transmit_cancel[a] <=#Tp 1'h0;
    end
    
    
    always @ (posedge clk or posedge rst)
    begin
      if (rst)
        txcmp[a] <= 1'h0;
      else if ((state == st_wait) & (txmsgbox == a) & tx_successful & (~tx_successful_q))
        txcmp[a] <=#Tp 1'h1;
      else if (we_txcmp & data_in[a])
        txcmp[a] <=#Tp 1'h0;
    end
    
    
    always @ (posedge clk or posedge rst)
    begin
      if (rst)
        rxselfreq[a] <= 1'h0;
      else if (we_rxselfreq)
        rxselfreq[a] <=#Tp data_in[a];
    end
    
    
  end //for
endgenerate
/* End: Tx controll register. */


/* Rx controll register. */
generate
  genvar b;
  for (b=0; b<32; b=b+1) begin :rxsts_reg


    always @ (posedge clk or posedge rst)
    begin
      if (rst)
        rxwait[b] <= 1'h0;
      else if (we_rxwait)
        rxwait[b] <=#Tp data_in[b];
    end
    
    
    always @ (posedge clk or posedge rst)
    begin
      if (rst)
        rxcmp[b] <= 1'h0;
      else if (rx_we_ff[b])
        rxcmp[b] <=#Tp 1'h1;
      else if (we_rxcmp & data_in[b])
        rxcmp[b] <=#Tp 1'h0;
    end
    
    
    always @ (posedge clk or posedge rst)
    begin
      if (rst)
        rxovrwrite[b] <= 1'h0;
      else if (rx_we_ff[b] & rxcmp[b])
        rxovrwrite[b] <=#Tp 1'h1;
      else if (read_rxovrwrite)
        rxovrwrite[b] <=#Tp 1'h0;
    end
    
    
  end //for
endgenerate
/* End: Rx controll register. */


/* This section is for EXTENDED mode */

/* Acceptance code register 1 */
can_register_asyn #(8, 8'h0) ACCEPTANCE_CODE_REG1
( .data_in(data_in[2*8+7:2*8+0]),
  .data_out(acceptance_code_1),
  .we(we_acceptance_code_1),
  .clk(clk),
  .rst(rst)
);
/* End: Acceptance code register */


/* Acceptance code register 2 */
can_register_asyn #(8, 8'h0) ACCEPTANCE_CODE_REG2
( .data_in(data_in[1*8+7:1*8+0]),
  .data_out(acceptance_code_2),
  .we(we_acceptance_code_2),
  .clk(clk),
  .rst(rst)
);
/* End: Acceptance code register */


/* Acceptance code register 3 */
can_register_asyn #(8, 8'h0) ACCEPTANCE_CODE_REG3
( .data_in(data_in[0*8+7:0*8+0]),
  .data_out(acceptance_code_3),
  .we(we_acceptance_code_3),
  .clk(clk),
  .rst(rst)
);
/* End: Acceptance code register */


/* Acceptance mask register 1 */
can_register_asyn #(8, 8'h0) ACCEPTANCE_MASK_REG1
( .data_in(data_in[2*8+7:2*8+0]),
  .data_out(acceptance_mask_1),
  .we(we_acceptance_mask_1),
  .clk(clk),
  .rst(rst)
);
/* End: Acceptance code register */


/* Acceptance mask register 2 */
can_register_asyn #(8, 8'h0) ACCEPTANCE_MASK_REG2
( .data_in(data_in[1*8+7:1*8+0]),
  .data_out(acceptance_mask_2),
  .we(we_acceptance_mask_2),
  .clk(clk),
  .rst(rst)
);
/* End: Acceptance code register */


/* Acceptance mask register 3 */
can_register_asyn #(8, 8'h0) ACCEPTANCE_MASK_REG3
( .data_in(data_in[0*8+7:0*8+0]),
  .data_out(acceptance_mask_3),
  .we(we_acceptance_mask_3),
  .clk(clk),
  .rst(rst)
);
/* End: Acceptance code register */


/* End: This section is for EXTENDED mode */




// Selecting massage read data 
reg [127:0] txmsgdata;
always @ (*)
begin
  txmsgdata = txdata[addr[7:4]];
end

// Reading data from registers
reg [31:0] data_out_reg;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    data_out_reg <= 32'b0;
  else if(addr[9:8] == 2'h0)
  begin
    case(addr[7:0])  /* synthesis parallel_case */ 
      8'h00   : data_out_reg <= {24'h0, 4'h0, mode_ext[3:1], mode[0]};
      8'h04   : data_out_reg <= {16'h0, txreq};
      8'h08   : data_out_reg <= {16'h0, txabort};
      8'h0C   : data_out_reg <= {16'h0, txcmp};
      8'h10   : data_out_reg <= {16'h0, transmit_cancel};
      8'h14   : data_out_reg <= rxwait;
      8'h18   : data_out_reg <= rxcmp;
      8'h1C   : data_out_reg <= rxovrwrite;
      8'h20   : data_out_reg <= {16'h0, rxselfreq};
      8'h24   : data_out_reg <= {24'h0, status};
      8'h28   : data_out_reg <= {24'h0, irq_reg};
      8'h2C   : data_out_reg <= {24'h0, irq_en_ext};
      8'h30   : data_out_reg <= irq_rxen;
      8'h34   : data_out_reg <= {clock_divider, 8'h0, bus_timing_1, bus_timing_0};
      8'h38   : data_out_reg <= {acceptance_code_0, acceptance_code_1, acceptance_code_2, acceptance_code_3};
      8'h3C   : data_out_reg <= {acceptance_mask_0, acceptance_mask_1, acceptance_mask_2, acceptance_mask_3};
      8'h40   : data_out_reg <= (extended_mode)? {8'h0, 4'h0, arbitration_lost_capture_mbox, 8'h0, 3'h0, arbitration_lost_capture[4:0]}: 32'h0;
      8'h44   : data_out_reg <= (extended_mode)? {8'h0, 4'h0, error_capture_code_mbox, 8'h0, error_capture_code}: 32'h0;
      8'h48   : data_out_reg <= {tx_err_cnt, rx_err_cnt, 8'h0, error_warning_limit};
      8'h4C   : data_out_reg <= {11'h0, rxdatawin, 16'h0};
      8'h70   : data_out_reg <= rxcode[rxdatawin];
      8'h74   : data_out_reg <= rxmask[rxdatawin];
      default : data_out_reg <= 32'h0;                                   // the rest is read as 0
    endcase
  end
  else
  begin
    case(addr[3:2])
      2'h0   : data_out_reg <= {txmsgdata[0*32+31], 2'h0, txmsgdata[0*32+28:0*32]};
      2'h1   : data_out_reg <= {27'h0, txmsgdata[1*32+4:1*32]};
      2'h2   : data_out_reg <= txmsgdata[2*32+31:2*32];
      2'h3   : data_out_reg <= txmsgdata[3*32+31:3*32];
    endcase
  end
end
always @ ( * )
begin
  if(~addr[9])
    data_out = data_out_reg;
  else
    case(addr[3:2])
      2'h0   : data_out = {rxmsgdata[0*32+31], 2'h0, rxmsgdata[0*32+28:0*32]};
      2'h1   : data_out = {27'h0, rxmsgdata[1*32+4:1*32]};
      2'h2   : data_out = rxmsgdata[2*32+31:2*32];
      2'h3   : data_out = rxmsgdata[3*32+31:3*32];
    endcase
end


// Some interrupts exist in basic mode and in extended mode. Since they are in different registers they need to be multiplexed.
assign data_overrun_irq_en  = data_overrun_irq_en_ext  ;
assign error_warning_irq_en = error_warning_irq_en_ext ;
assign transmit_irq_en      = transmit_irq_en_ext      ;
assign receive_irq_en       = receive_irq_en_ext       ;


reg transmit_cancel_irq;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    transmit_cancel_irq <= 1'b0;
  else if (we_txcancel)
    transmit_cancel_irq <=#Tp 1'b0;
  else if (|transmit_cancel & transmit_cancel_irq_en)
    transmit_cancel_irq <=#Tp 1'b1;
//  else if (reset_mode)
  else
    transmit_cancel_irq <=#Tp 1'b0;
end


reg data_overrun_irq;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    data_overrun_irq <= 1'b0;
  else if (read_rxovrwrite)
    data_overrun_irq <=#Tp 1'b0;
  else if (|(rxovrwrite & irq_rxen) & data_overrun_irq_en)
    data_overrun_irq <=#Tp 1'b1;
//  else if (reset_mode)
  else
    data_overrun_irq <=#Tp 1'b0;
end


reg transmit_irq;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    transmit_irq <= 1'b0;
//  else if (reset_mode || read_irq_reg)
//    transmit_irq <=#Tp 1'b0;
//  else if (transmit_buffer_status & (~transmit_buffer_status_q) & transmit_irq_en)
//    transmit_irq <=#Tp 1'b1;  else if (reset_mode)
  else if (we_txcmp)
    transmit_irq <=#Tp 1'b0;
  else if (|txcmp & transmit_irq_en)
    transmit_irq <=#Tp 1'b1;
  else
    transmit_irq <=#Tp 1'b0;
end


reg receive_irq;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    receive_irq <= 1'b0;
  else if (we_rxcmp)
    receive_irq <=#Tp 1'b0;
  else if (|(rxcmp & irq_rxen) & receive_irq_en)
    receive_irq <=#Tp 1'b1;
//  else if (reset_mode)
  else
    receive_irq <=#Tp 1'b0;
end


reg error_irq;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    error_irq <= 1'b0;
  else if (((error_status ^ error_status_q) | (node_bus_off ^ node_bus_off_q)) & error_warning_irq_en)
    error_irq <=#Tp 1'b1;
  else if (read_irq_reg)
    error_irq <=#Tp 1'b0;
end


reg bus_error_irq;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    bus_error_irq <= 1'b0;
  else if (set_bus_error_irq & bus_error_irq_en)
    bus_error_irq <=#Tp 1'b1;
  else if (reset_mode || read_irq_reg)
    bus_error_irq <=#Tp 1'b0;
end


reg arbitration_lost_irq;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    arbitration_lost_irq <= 1'b0;
  else if (set_arbitration_lost_irq & arbitration_lost_irq_en)
    arbitration_lost_irq <=#Tp 1'b1;
  else if (reset_mode || read_irq_reg)
    arbitration_lost_irq <=#Tp 1'b0;
end



reg error_passive_irq;
always @ (posedge clk or posedge rst)
begin
  if (rst)
    error_passive_irq <= 1'b0;
  else if ((node_error_passive & (~node_error_passive_q) | (~node_error_passive) & node_error_passive_q & node_error_active) & error_passive_irq_en)
    error_passive_irq <=#Tp 1'b1;
  else if (reset_mode || read_irq_reg)
    error_passive_irq <=#Tp 1'b0;
end



assign irq_reg = {bus_error_irq, arbitration_lost_irq, error_passive_irq, transmit_cancel_irq, data_overrun_irq, error_irq, transmit_irq, receive_irq};

assign irq = data_overrun_irq | transmit_irq | receive_irq | error_irq | bus_error_irq | arbitration_lost_irq | error_passive_irq | transmit_cancel_irq;

wire irq_clr = we_txcancel | read_rxovrwrite | we_txcmp | we_rxcmp;

always @ (posedge clk or posedge rst)
begin
  if (rst)
    irq_n <= 1'b1;
  else if (read_irq_reg || release_buffer || irq_clr)
    irq_n <=#Tp 1'b1;
  else if (irq)
    irq_n <=#Tp 1'b0;
end



endmodule
