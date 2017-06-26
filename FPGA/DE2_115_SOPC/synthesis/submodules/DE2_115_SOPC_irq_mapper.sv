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


// $Id: //acds/rel/13.1up/ip/merlin/altera_irq_mapper/altera_irq_mapper.sv.terp#1 $
// $Revision: #1 $
// $Date: 2013/11/05 $
// $Author: swbranch $

// -------------------------------------------------------
// Altera IRQ Mapper
//
// Parameters
//   NUM_RCVRS        : 28
//   SENDER_IRW_WIDTH : 32
//   IRQ_MAP          : 0:0,1:6,2:5,3:7,4:1,5:8,6:9,7:16,8:17,9:18,10:19,11:20,12:21,13:22,14:23,15:24,16:25,17:26,18:27,19:28,20:29,21:30,22:31,23:10,24:3,25:4,26:12,27:13
//
// -------------------------------------------------------

`timescale 1 ns / 1 ns

module DE2_115_SOPC_irq_mapper
(
    // -------------------
    // Clock & Reset
    // -------------------
    input clk,
    input reset,

    // -------------------
    // IRQ Receivers
    // -------------------
    input                receiver0_irq,
    input                receiver1_irq,
    input                receiver2_irq,
    input                receiver3_irq,
    input                receiver4_irq,
    input                receiver5_irq,
    input                receiver6_irq,
    input                receiver7_irq,
    input                receiver8_irq,
    input                receiver9_irq,
    input                receiver10_irq,
    input                receiver11_irq,
    input                receiver12_irq,
    input                receiver13_irq,
    input                receiver14_irq,
    input                receiver15_irq,
    input                receiver16_irq,
    input                receiver17_irq,
    input                receiver18_irq,
    input                receiver19_irq,
    input                receiver20_irq,
    input                receiver21_irq,
    input                receiver22_irq,
    input                receiver23_irq,
    input                receiver24_irq,
    input                receiver25_irq,
    input                receiver26_irq,
    input                receiver27_irq,

    // -------------------
    // Command Source (Output)
    // -------------------
    output reg [31 : 0] sender_irq
);


    always @* begin
	sender_irq = 0;

        sender_irq[0] = receiver0_irq;
        sender_irq[6] = receiver1_irq;
        sender_irq[5] = receiver2_irq;
        sender_irq[7] = receiver3_irq;
        sender_irq[1] = receiver4_irq;
        sender_irq[8] = receiver5_irq;
        sender_irq[9] = receiver6_irq;
        sender_irq[16] = receiver7_irq;
        sender_irq[17] = receiver8_irq;
        sender_irq[18] = receiver9_irq;
        sender_irq[19] = receiver10_irq;
        sender_irq[20] = receiver11_irq;
        sender_irq[21] = receiver12_irq;
        sender_irq[22] = receiver13_irq;
        sender_irq[23] = receiver14_irq;
        sender_irq[24] = receiver15_irq;
        sender_irq[25] = receiver16_irq;
        sender_irq[26] = receiver17_irq;
        sender_irq[27] = receiver18_irq;
        sender_irq[28] = receiver19_irq;
        sender_irq[29] = receiver20_irq;
        sender_irq[30] = receiver21_irq;
        sender_irq[31] = receiver22_irq;
        sender_irq[10] = receiver23_irq;
        sender_irq[3] = receiver24_irq;
        sender_irq[4] = receiver25_irq;
        sender_irq[12] = receiver26_irq;
        sender_irq[13] = receiver27_irq;
    end

endmodule


