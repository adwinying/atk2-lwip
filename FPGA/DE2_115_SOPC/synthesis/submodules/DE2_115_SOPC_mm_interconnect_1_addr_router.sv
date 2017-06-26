// (C) 2001-2014 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// (C) 2001-2013 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// $Id: //acds/rel/13.1up/ip/merlin/altera_merlin_router/altera_merlin_router.sv.terp#1 $
// $Revision: #1 $
// $Date: 2013/11/05 $
// $Author: swbranch $

// -------------------------------------------------------
// Merlin Router
//
// Asserts the appropriate one-hot encoded channel based on 
// either (a) the address or (b) the dest id. The DECODER_TYPE
// parameter controls this behaviour. 0 means address decoder,
// 1 means dest id decoder.
//
// In the case of (a), it also sets the destination id.
// -------------------------------------------------------

`timescale 1 ns / 1 ns

module DE2_115_SOPC_mm_interconnect_1_addr_router_default_decode
  #(
     parameter DEFAULT_CHANNEL = 0,
               DEFAULT_WR_CHANNEL = -1,
               DEFAULT_RD_CHANNEL = -1,
               DEFAULT_DESTID = 18 
   )
  (output [77 - 72 : 0] default_destination_id,
   output [37-1 : 0] default_wr_channel,
   output [37-1 : 0] default_rd_channel,
   output [37-1 : 0] default_src_channel
  );

  assign default_destination_id = 
    DEFAULT_DESTID[77 - 72 : 0];

  generate begin : default_decode
    if (DEFAULT_CHANNEL == -1) begin
      assign default_src_channel = '0;
    end
    else begin
      assign default_src_channel = 37'b1 << DEFAULT_CHANNEL;
    end
  end
  endgenerate

  generate begin : default_decode_rw
    if (DEFAULT_RD_CHANNEL == -1) begin
      assign default_wr_channel = '0;
      assign default_rd_channel = '0;
    end
    else begin
      assign default_wr_channel = 37'b1 << DEFAULT_WR_CHANNEL;
      assign default_rd_channel = 37'b1 << DEFAULT_RD_CHANNEL;
    end
  end
  endgenerate

endmodule


module DE2_115_SOPC_mm_interconnect_1_addr_router
(
    // -------------------
    // Clock & Reset
    // -------------------
    input clk,
    input reset,

    // -------------------
    // Command Sink (Input)
    // -------------------
    input                       sink_valid,
    input  [91-1 : 0]    sink_data,
    input                       sink_startofpacket,
    input                       sink_endofpacket,
    output                      sink_ready,

    // -------------------
    // Command Source (Output)
    // -------------------
    output                          src_valid,
    output reg [91-1    : 0] src_data,
    output reg [37-1 : 0] src_channel,
    output                          src_startofpacket,
    output                          src_endofpacket,
    input                           src_ready
);

    // -------------------------------------------------------
    // Local parameters and variables
    // -------------------------------------------------------
    localparam PKT_ADDR_H = 46;
    localparam PKT_ADDR_L = 36;
    localparam PKT_DEST_ID_H = 77;
    localparam PKT_DEST_ID_L = 72;
    localparam PKT_PROTECTION_H = 81;
    localparam PKT_PROTECTION_L = 79;
    localparam ST_DATA_W = 91;
    localparam ST_CHANNEL_W = 37;
    localparam DECODER_TYPE = 0;

    localparam PKT_TRANS_WRITE = 49;
    localparam PKT_TRANS_READ  = 50;

    localparam PKT_ADDR_W = PKT_ADDR_H-PKT_ADDR_L + 1;
    localparam PKT_DEST_ID_W = PKT_DEST_ID_H-PKT_DEST_ID_L + 1;



    // -------------------------------------------------------
    // Figure out the number of bits to mask off for each slave span
    // during address decoding
    // -------------------------------------------------------
    localparam PAD0 = log2ceil(64'h150 - 64'h140); 
    localparam PAD1 = log2ceil(64'h180 - 64'h160); 
    localparam PAD2 = log2ceil(64'h1a8 - 64'h1a0); 
    localparam PAD3 = log2ceil(64'h1b0 - 64'h1a8); 
    localparam PAD4 = log2ceil(64'h1e0 - 64'h1c0); 
    localparam PAD5 = log2ceil(64'h220 - 64'h200); 
    localparam PAD6 = log2ceil(64'h240 - 64'h220); 
    localparam PAD7 = log2ceil(64'h260 - 64'h240); 
    localparam PAD8 = log2ceil(64'h280 - 64'h260); 
    localparam PAD9 = log2ceil(64'h2a0 - 64'h280); 
    localparam PAD10 = log2ceil(64'h2c0 - 64'h2a0); 
    localparam PAD11 = log2ceil(64'h2e0 - 64'h2c0); 
    localparam PAD12 = log2ceil(64'h300 - 64'h2e0); 
    localparam PAD13 = log2ceil(64'h320 - 64'h300); 
    localparam PAD14 = log2ceil(64'h340 - 64'h320); 
    localparam PAD15 = log2ceil(64'h360 - 64'h340); 
    localparam PAD16 = log2ceil(64'h380 - 64'h360); 
    localparam PAD17 = log2ceil(64'h3a0 - 64'h380); 
    localparam PAD18 = log2ceil(64'h3c0 - 64'h3a0); 
    localparam PAD19 = log2ceil(64'h3e0 - 64'h3c0); 
    localparam PAD20 = log2ceil(64'h400 - 64'h3e0); 
    localparam PAD21 = log2ceil(64'h410 - 64'h400); 
    localparam PAD22 = log2ceil(64'h420 - 64'h410); 
    localparam PAD23 = log2ceil(64'h430 - 64'h420); 
    localparam PAD24 = log2ceil(64'h440 - 64'h430); 
    localparam PAD25 = log2ceil(64'h460 - 64'h440); 
    localparam PAD26 = log2ceil(64'h470 - 64'h460); 
    localparam PAD27 = log2ceil(64'h480 - 64'h470); 
    localparam PAD28 = log2ceil(64'h490 - 64'h480); 
    localparam PAD29 = log2ceil(64'h4a0 - 64'h490); 
    localparam PAD30 = log2ceil(64'h4b0 - 64'h4a0); 
    localparam PAD31 = log2ceil(64'h4c0 - 64'h4b0); 
    localparam PAD32 = log2ceil(64'h4d0 - 64'h4c0); 
    localparam PAD33 = log2ceil(64'h4e0 - 64'h4d0); 
    localparam PAD34 = log2ceil(64'h4f0 - 64'h4e0); 
    localparam PAD35 = log2ceil(64'h500 - 64'h4f0); 
    localparam PAD36 = log2ceil(64'h520 - 64'h500); 
    // -------------------------------------------------------
    // Work out which address bits are significant based on the
    // address range of the slaves. If the required width is too
    // large or too small, we use the address field width instead.
    // -------------------------------------------------------
    localparam ADDR_RANGE = 64'h520;
    localparam RANGE_ADDR_WIDTH = log2ceil(ADDR_RANGE);
    localparam OPTIMIZED_ADDR_H = (RANGE_ADDR_WIDTH > PKT_ADDR_W) ||
                                  (RANGE_ADDR_WIDTH == 0) ?
                                        PKT_ADDR_H :
                                        PKT_ADDR_L + RANGE_ADDR_WIDTH - 1;

    localparam RG = RANGE_ADDR_WIDTH-1;
    localparam REAL_ADDRESS_RANGE = OPTIMIZED_ADDR_H - PKT_ADDR_L;

      reg [PKT_ADDR_W-1 : 0] address;
      always @* begin
        address = {PKT_ADDR_W{1'b0}};
        address [REAL_ADDRESS_RANGE:0] = sink_data[OPTIMIZED_ADDR_H : PKT_ADDR_L];
      end   

    // -------------------------------------------------------
    // Pass almost everything through, untouched
    // -------------------------------------------------------
    assign sink_ready        = src_ready;
    assign src_valid         = sink_valid;
    assign src_startofpacket = sink_startofpacket;
    assign src_endofpacket   = sink_endofpacket;
    wire [PKT_DEST_ID_W-1:0] default_destid;
    wire [37-1 : 0] default_src_channel;




    // -------------------------------------------------------
    // Write and read transaction signals
    // -------------------------------------------------------
    wire read_transaction;
    assign read_transaction  = sink_data[PKT_TRANS_READ];


    DE2_115_SOPC_mm_interconnect_1_addr_router_default_decode the_default_decode(
      .default_destination_id (default_destid),
      .default_wr_channel   (),
      .default_rd_channel   (),
      .default_src_channel  (default_src_channel)
    );

    always @* begin
        src_data    = sink_data;
        src_channel = default_src_channel;
        src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = default_destid;

        // --------------------------------------------------
        // Address Decoder
        // Sets the channel and destination ID based on the address
        // --------------------------------------------------

    // ( 0x140 .. 0x150 )
    if ( {address[RG:PAD0],{PAD0{1'b0}}} == 11'h140   ) begin
            src_channel = 37'b1000000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 10;
    end

    // ( 0x160 .. 0x180 )
    if ( {address[RG:PAD1],{PAD1{1'b0}}} == 11'h160   ) begin
            src_channel = 37'b0000000000000000000000000000000000001;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 18;
    end

    // ( 0x1a0 .. 0x1a8 )
    if ( {address[RG:PAD2],{PAD2{1'b0}}} == 11'h1a0   ) begin
            src_channel = 37'b0000000000000000001000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 5;
    end

    // ( 0x1a8 .. 0x1b0 )
    if ( {address[RG:PAD3],{PAD3{1'b0}}} == 11'h1a8  && read_transaction  ) begin
            src_channel = 37'b0000000000000000000000000000000000010;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 19;
    end

    // ( 0x1c0 .. 0x1e0 )
    if ( {address[RG:PAD4],{PAD4{1'b0}}} == 11'h1c0   ) begin
            src_channel = 37'b0000000000000000010000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 20;
    end

    // ( 0x200 .. 0x220 )
    if ( {address[RG:PAD5],{PAD5{1'b0}}} == 11'h200   ) begin
            src_channel = 37'b0000000000000000100000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 21;
    end

    // ( 0x220 .. 0x240 )
    if ( {address[RG:PAD6],{PAD6{1'b0}}} == 11'h220   ) begin
            src_channel = 37'b0000000000000001000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 28;
    end

    // ( 0x240 .. 0x260 )
    if ( {address[RG:PAD7],{PAD7{1'b0}}} == 11'h240   ) begin
            src_channel = 37'b0000000000000010000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 29;
    end

    // ( 0x260 .. 0x280 )
    if ( {address[RG:PAD8],{PAD8{1'b0}}} == 11'h260   ) begin
            src_channel = 37'b0000000000000100000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 30;
    end

    // ( 0x280 .. 0x2a0 )
    if ( {address[RG:PAD9],{PAD9{1'b0}}} == 11'h280   ) begin
            src_channel = 37'b0000000000001000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 31;
    end

    // ( 0x2a0 .. 0x2c0 )
    if ( {address[RG:PAD10],{PAD10{1'b0}}} == 11'h2a0   ) begin
            src_channel = 37'b0000000000010000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 32;
    end

    // ( 0x2c0 .. 0x2e0 )
    if ( {address[RG:PAD11],{PAD11{1'b0}}} == 11'h2c0   ) begin
            src_channel = 37'b0000000000100000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 33;
    end

    // ( 0x2e0 .. 0x300 )
    if ( {address[RG:PAD12],{PAD12{1'b0}}} == 11'h2e0   ) begin
            src_channel = 37'b0000000001000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 34;
    end

    // ( 0x300 .. 0x320 )
    if ( {address[RG:PAD13],{PAD13{1'b0}}} == 11'h300   ) begin
            src_channel = 37'b0000000010000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 35;
    end

    // ( 0x320 .. 0x340 )
    if ( {address[RG:PAD14],{PAD14{1'b0}}} == 11'h320   ) begin
            src_channel = 37'b0000000100000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 36;
    end

    // ( 0x340 .. 0x360 )
    if ( {address[RG:PAD15],{PAD15{1'b0}}} == 11'h340   ) begin
            src_channel = 37'b0000001000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 22;
    end

    // ( 0x360 .. 0x380 )
    if ( {address[RG:PAD16],{PAD16{1'b0}}} == 11'h360   ) begin
            src_channel = 37'b0000010000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 23;
    end

    // ( 0x380 .. 0x3a0 )
    if ( {address[RG:PAD17],{PAD17{1'b0}}} == 11'h380   ) begin
            src_channel = 37'b0000100000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 24;
    end

    // ( 0x3a0 .. 0x3c0 )
    if ( {address[RG:PAD18],{PAD18{1'b0}}} == 11'h3a0   ) begin
            src_channel = 37'b0001000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 25;
    end

    // ( 0x3c0 .. 0x3e0 )
    if ( {address[RG:PAD19],{PAD19{1'b0}}} == 11'h3c0   ) begin
            src_channel = 37'b0010000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 26;
    end

    // ( 0x3e0 .. 0x400 )
    if ( {address[RG:PAD20],{PAD20{1'b0}}} == 11'h3e0   ) begin
            src_channel = 37'b0100000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 27;
    end

    // ( 0x400 .. 0x410 )
    if ( {address[RG:PAD21],{PAD21{1'b0}}} == 11'h400   ) begin
            src_channel = 37'b0000000000000000000000000000000000100;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 6;
    end

    // ( 0x410 .. 0x420 )
    if ( {address[RG:PAD22],{PAD22{1'b0}}} == 11'h410   ) begin
            src_channel = 37'b0000000000000000000000000000000001000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 17;
    end

    // ( 0x420 .. 0x430 )
    if ( {address[RG:PAD23],{PAD23{1'b0}}} == 11'h420   ) begin
            src_channel = 37'b0000000000000000000000000000000010000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 8;
    end

    // ( 0x430 .. 0x440 )
    if ( {address[RG:PAD24],{PAD24{1'b0}}} == 11'h430   ) begin
            src_channel = 37'b0000000000000000000000000000000100000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 9;
    end

    // ( 0x440 .. 0x460 )
    if ( {address[RG:PAD25],{PAD25{1'b0}}} == 11'h440   ) begin
            src_channel = 37'b0000000000000000000000000000001000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 11;
    end

    // ( 0x460 .. 0x470 )
    if ( {address[RG:PAD26],{PAD26{1'b0}}} == 11'h460   ) begin
            src_channel = 37'b0000000000000000000000000000010000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 2;
    end

    // ( 0x470 .. 0x480 )
    if ( {address[RG:PAD27],{PAD27{1'b0}}} == 11'h470   ) begin
            src_channel = 37'b0000000000000000000000000000100000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 3;
    end

    // ( 0x480 .. 0x490 )
    if ( {address[RG:PAD28],{PAD28{1'b0}}} == 11'h480   ) begin
            src_channel = 37'b0000000000000000000000000001000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 0;
    end

    // ( 0x490 .. 0x4a0 )
    if ( {address[RG:PAD29],{PAD29{1'b0}}} == 11'h490   ) begin
            src_channel = 37'b0000000000000000000000000010000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 1;
    end

    // ( 0x4a0 .. 0x4b0 )
    if ( {address[RG:PAD30],{PAD30{1'b0}}} == 11'h4a0   ) begin
            src_channel = 37'b0000000000000000000000000100000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 7;
    end

    // ( 0x4b0 .. 0x4c0 )
    if ( {address[RG:PAD31],{PAD31{1'b0}}} == 11'h4b0  && read_transaction  ) begin
            src_channel = 37'b0000000000000000000000001000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 4;
    end

    // ( 0x4c0 .. 0x4d0 )
    if ( {address[RG:PAD32],{PAD32{1'b0}}} == 11'h4c0   ) begin
            src_channel = 37'b0000000000000000000000100000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 12;
    end

    // ( 0x4d0 .. 0x4e0 )
    if ( {address[RG:PAD33],{PAD33{1'b0}}} == 11'h4d0   ) begin
            src_channel = 37'b0000000000000000000001000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 13;
    end

    // ( 0x4e0 .. 0x4f0 )
    if ( {address[RG:PAD34],{PAD34{1'b0}}} == 11'h4e0   ) begin
            src_channel = 37'b0000000000000000000010000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 14;
    end

    // ( 0x4f0 .. 0x500 )
    if ( {address[RG:PAD35],{PAD35{1'b0}}} == 11'h4f0  && read_transaction  ) begin
            src_channel = 37'b0000000000000000000100000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 15;
    end

    // ( 0x500 .. 0x520 )
    if ( {address[RG:PAD36],{PAD36{1'b0}}} == 11'h500   ) begin
            src_channel = 37'b0000000000000000000000010000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 16;
    end

end


    // --------------------------------------------------
    // Ceil(log2()) function
    // --------------------------------------------------
    function integer log2ceil;
        input reg[65:0] val;
        reg [65:0] i;

        begin
            i = 1;
            log2ceil = 0;

            while (i < val) begin
                log2ceil = log2ceil + 1;
                i = i << 1;
            end
        end
    endfunction

endmodule


