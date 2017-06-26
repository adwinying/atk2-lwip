// DE2_115_SOPC_vic_0.v

// This file was auto-generated from altera_vic_hw.tcl.  If you edit it your changes
// will probably be lost.
// 
// Generated using ACDS version 13.1 182 at 2015.03.26.09:07:18

`timescale 1 ps / 1 ps
module DE2_115_SOPC_vic_0 (
		input  wire        clk_clk,                        //                      clk.clk
		input  wire        clk_reset_reset,                //                clk_reset.reset
		input  wire [31:0] irq_input_irq,                  //                irq_input.irq
		input  wire        csr_access_read,                //               csr_access.read
		input  wire        csr_access_write,               //                         .write
		input  wire [7:0]  csr_access_address,             //                         .address
		input  wire [31:0] csr_access_writedata,           //                         .writedata
		output wire [31:0] csr_access_readdata,            //                         .readdata
		output wire        interrupt_controller_out_valid, // interrupt_controller_out.valid
		output wire [44:0] interrupt_controller_out_data   //                         .data
	);

	wire         vic_csr_out0_valid;      // vic_csr:out0_valid -> vic_priority:in0_valid
	wire  [18:0] vic_csr_out0_data;       // vic_csr:out0_data -> vic_priority:in0_data
	wire         vic_csr_out1_valid;      // vic_csr:out1_valid -> vic_priority:in1_valid
	wire  [18:0] vic_csr_out1_data;       // vic_csr:out1_data -> vic_priority:in1_data
	wire         vic_csr_out2_valid;      // vic_csr:out2_valid -> vic_priority:in2_valid
	wire  [18:0] vic_csr_out2_data;       // vic_csr:out2_data -> vic_priority:in2_data
	wire         vic_csr_out3_valid;      // vic_csr:out3_valid -> vic_priority:in3_valid
	wire  [18:0] vic_csr_out3_data;       // vic_csr:out3_data -> vic_priority:in3_data
	wire         vic_csr_out4_valid;      // vic_csr:out4_valid -> vic_priority:in4_valid
	wire  [18:0] vic_csr_out4_data;       // vic_csr:out4_data -> vic_priority:in4_data
	wire         vic_csr_out5_valid;      // vic_csr:out5_valid -> vic_priority:in5_valid
	wire  [18:0] vic_csr_out5_data;       // vic_csr:out5_data -> vic_priority:in5_data
	wire         vic_csr_out6_valid;      // vic_csr:out6_valid -> vic_priority:in6_valid
	wire  [18:0] vic_csr_out6_data;       // vic_csr:out6_data -> vic_priority:in6_data
	wire         vic_csr_out7_valid;      // vic_csr:out7_valid -> vic_priority:in7_valid
	wire  [18:0] vic_csr_out7_data;       // vic_csr:out7_data -> vic_priority:in7_data
	wire         vic_csr_out8_valid;      // vic_csr:out8_valid -> vic_priority:in8_valid
	wire  [18:0] vic_csr_out8_data;       // vic_csr:out8_data -> vic_priority:in8_data
	wire         vic_csr_out9_valid;      // vic_csr:out9_valid -> vic_priority:in9_valid
	wire  [18:0] vic_csr_out9_data;       // vic_csr:out9_data -> vic_priority:in9_data
	wire         vic_csr_out10_valid;     // vic_csr:out10_valid -> vic_priority:in10_valid
	wire  [18:0] vic_csr_out10_data;      // vic_csr:out10_data -> vic_priority:in10_data
	wire         vic_csr_out11_valid;     // vic_csr:out11_valid -> vic_priority:in11_valid
	wire  [18:0] vic_csr_out11_data;      // vic_csr:out11_data -> vic_priority:in11_data
	wire         vic_csr_out12_valid;     // vic_csr:out12_valid -> vic_priority:in12_valid
	wire  [18:0] vic_csr_out12_data;      // vic_csr:out12_data -> vic_priority:in12_data
	wire         vic_csr_out13_valid;     // vic_csr:out13_valid -> vic_priority:in13_valid
	wire  [18:0] vic_csr_out13_data;      // vic_csr:out13_data -> vic_priority:in13_data
	wire         vic_csr_out14_valid;     // vic_csr:out14_valid -> vic_priority:in14_valid
	wire  [18:0] vic_csr_out14_data;      // vic_csr:out14_data -> vic_priority:in14_data
	wire         vic_csr_out15_valid;     // vic_csr:out15_valid -> vic_priority:in15_valid
	wire  [18:0] vic_csr_out15_data;      // vic_csr:out15_data -> vic_priority:in15_data
	wire         vic_csr_out16_valid;     // vic_csr:out16_valid -> vic_priority:in16_valid
	wire  [18:0] vic_csr_out16_data;      // vic_csr:out16_data -> vic_priority:in16_data
	wire         vic_csr_out17_valid;     // vic_csr:out17_valid -> vic_priority:in17_valid
	wire  [18:0] vic_csr_out17_data;      // vic_csr:out17_data -> vic_priority:in17_data
	wire         vic_csr_out18_valid;     // vic_csr:out18_valid -> vic_priority:in18_valid
	wire  [18:0] vic_csr_out18_data;      // vic_csr:out18_data -> vic_priority:in18_data
	wire         vic_csr_out19_valid;     // vic_csr:out19_valid -> vic_priority:in19_valid
	wire  [18:0] vic_csr_out19_data;      // vic_csr:out19_data -> vic_priority:in19_data
	wire         vic_csr_out20_valid;     // vic_csr:out20_valid -> vic_priority:in20_valid
	wire  [18:0] vic_csr_out20_data;      // vic_csr:out20_data -> vic_priority:in20_data
	wire         vic_csr_out21_valid;     // vic_csr:out21_valid -> vic_priority:in21_valid
	wire  [18:0] vic_csr_out21_data;      // vic_csr:out21_data -> vic_priority:in21_data
	wire         vic_csr_out22_valid;     // vic_csr:out22_valid -> vic_priority:in22_valid
	wire  [18:0] vic_csr_out22_data;      // vic_csr:out22_data -> vic_priority:in22_data
	wire         vic_csr_out23_valid;     // vic_csr:out23_valid -> vic_priority:in23_valid
	wire  [18:0] vic_csr_out23_data;      // vic_csr:out23_data -> vic_priority:in23_data
	wire         vic_csr_out24_valid;     // vic_csr:out24_valid -> vic_priority:in24_valid
	wire  [18:0] vic_csr_out24_data;      // vic_csr:out24_data -> vic_priority:in24_data
	wire         vic_csr_out25_valid;     // vic_csr:out25_valid -> vic_priority:in25_valid
	wire  [18:0] vic_csr_out25_data;      // vic_csr:out25_data -> vic_priority:in25_data
	wire         vic_csr_out26_valid;     // vic_csr:out26_valid -> vic_priority:in26_valid
	wire  [18:0] vic_csr_out26_data;      // vic_csr:out26_data -> vic_priority:in26_data
	wire         vic_csr_out27_valid;     // vic_csr:out27_valid -> vic_priority:in27_valid
	wire  [18:0] vic_csr_out27_data;      // vic_csr:out27_data -> vic_priority:in27_data
	wire         vic_csr_out28_valid;     // vic_csr:out28_valid -> vic_priority:in28_valid
	wire  [18:0] vic_csr_out28_data;      // vic_csr:out28_data -> vic_priority:in28_data
	wire         vic_csr_out29_valid;     // vic_csr:out29_valid -> vic_priority:in29_valid
	wire  [18:0] vic_csr_out29_data;      // vic_csr:out29_data -> vic_priority:in29_data
	wire         vic_csr_out30_valid;     // vic_csr:out30_valid -> vic_priority:in30_valid
	wire  [18:0] vic_csr_out30_data;      // vic_csr:out30_data -> vic_priority:in30_data
	wire         vic_csr_out31_valid;     // vic_csr:out31_valid -> vic_priority:in31_valid
	wire  [18:0] vic_csr_out31_data;      // vic_csr:out31_data -> vic_priority:in31_data
	wire         vic_priority_out_valid;  // vic_priority:pri_valid -> vic_vector:in_valid
	wire  [18:0] vic_priority_out_data;   // vic_priority:pri_data -> vic_vector:in_data
	wire         vic_csr_control_valid;   // vic_csr:control_valid -> vic_vector:control_valid
	wire  [34:0] vic_csr_control_data;    // vic_csr:control_data -> vic_vector:control_data
	wire         vic_vector_status_valid; // vic_vector:status_valid -> vic_csr:status_valid
	wire  [37:0] vic_vector_status_data;  // vic_vector:status_data -> vic_csr:status_data

	altera_vic_csr #(
		.NUMBER_OF_INT_PORTS (32),
		.RRS_WIDTH           (6),
		.RIL_WIDTH           (6),
		.DAISY_CHAIN_ENABLE  (0)
	) vic_csr (
		.inr_i1_irq       (irq_input_irq),                                     //        i1.irq
		.avs_s1_read      (csr_access_read),                                   //        s1.read
		.avs_s1_write     (csr_access_write),                                  //          .write
		.avs_s1_address   (csr_access_address),                                //          .address
		.avs_s1_writedata (csr_access_writedata),                              //          .writedata
		.avs_s1_readdata  (csr_access_readdata),                               //          .readdata
		.out0_valid       (vic_csr_out0_valid),                                //      out0.valid
		.out0_data        (vic_csr_out0_data),                                 //          .data
		.out1_valid       (vic_csr_out1_valid),                                //      out1.valid
		.out1_data        (vic_csr_out1_data),                                 //          .data
		.out2_valid       (vic_csr_out2_valid),                                //      out2.valid
		.out2_data        (vic_csr_out2_data),                                 //          .data
		.out3_valid       (vic_csr_out3_valid),                                //      out3.valid
		.out3_data        (vic_csr_out3_data),                                 //          .data
		.out4_valid       (vic_csr_out4_valid),                                //      out4.valid
		.out4_data        (vic_csr_out4_data),                                 //          .data
		.out5_valid       (vic_csr_out5_valid),                                //      out5.valid
		.out5_data        (vic_csr_out5_data),                                 //          .data
		.out6_valid       (vic_csr_out6_valid),                                //      out6.valid
		.out6_data        (vic_csr_out6_data),                                 //          .data
		.out7_valid       (vic_csr_out7_valid),                                //      out7.valid
		.out7_data        (vic_csr_out7_data),                                 //          .data
		.out8_valid       (vic_csr_out8_valid),                                //      out8.valid
		.out8_data        (vic_csr_out8_data),                                 //          .data
		.out9_valid       (vic_csr_out9_valid),                                //      out9.valid
		.out9_data        (vic_csr_out9_data),                                 //          .data
		.out10_valid      (vic_csr_out10_valid),                               //     out10.valid
		.out10_data       (vic_csr_out10_data),                                //          .data
		.out11_valid      (vic_csr_out11_valid),                               //     out11.valid
		.out11_data       (vic_csr_out11_data),                                //          .data
		.out12_valid      (vic_csr_out12_valid),                               //     out12.valid
		.out12_data       (vic_csr_out12_data),                                //          .data
		.out13_valid      (vic_csr_out13_valid),                               //     out13.valid
		.out13_data       (vic_csr_out13_data),                                //          .data
		.out14_valid      (vic_csr_out14_valid),                               //     out14.valid
		.out14_data       (vic_csr_out14_data),                                //          .data
		.out15_valid      (vic_csr_out15_valid),                               //     out15.valid
		.out15_data       (vic_csr_out15_data),                                //          .data
		.out16_valid      (vic_csr_out16_valid),                               //     out16.valid
		.out16_data       (vic_csr_out16_data),                                //          .data
		.out17_valid      (vic_csr_out17_valid),                               //     out17.valid
		.out17_data       (vic_csr_out17_data),                                //          .data
		.out18_valid      (vic_csr_out18_valid),                               //     out18.valid
		.out18_data       (vic_csr_out18_data),                                //          .data
		.out19_valid      (vic_csr_out19_valid),                               //     out19.valid
		.out19_data       (vic_csr_out19_data),                                //          .data
		.out20_valid      (vic_csr_out20_valid),                               //     out20.valid
		.out20_data       (vic_csr_out20_data),                                //          .data
		.out21_valid      (vic_csr_out21_valid),                               //     out21.valid
		.out21_data       (vic_csr_out21_data),                                //          .data
		.out22_valid      (vic_csr_out22_valid),                               //     out22.valid
		.out22_data       (vic_csr_out22_data),                                //          .data
		.out23_valid      (vic_csr_out23_valid),                               //     out23.valid
		.out23_data       (vic_csr_out23_data),                                //          .data
		.out24_valid      (vic_csr_out24_valid),                               //     out24.valid
		.out24_data       (vic_csr_out24_data),                                //          .data
		.out25_valid      (vic_csr_out25_valid),                               //     out25.valid
		.out25_data       (vic_csr_out25_data),                                //          .data
		.out26_valid      (vic_csr_out26_valid),                               //     out26.valid
		.out26_data       (vic_csr_out26_data),                                //          .data
		.out27_valid      (vic_csr_out27_valid),                               //     out27.valid
		.out27_data       (vic_csr_out27_data),                                //          .data
		.out28_valid      (vic_csr_out28_valid),                               //     out28.valid
		.out28_data       (vic_csr_out28_data),                                //          .data
		.out29_valid      (vic_csr_out29_valid),                               //     out29.valid
		.out29_data       (vic_csr_out29_data),                                //          .data
		.out30_valid      (vic_csr_out30_valid),                               //     out30.valid
		.out30_data       (vic_csr_out30_data),                                //          .data
		.out31_valid      (vic_csr_out31_valid),                               //     out31.valid
		.out31_data       (vic_csr_out31_data),                                //          .data
		.control_valid    (vic_csr_control_valid),                             //   control.valid
		.control_data     (vic_csr_control_data),                              //          .data
		.status_valid     (vic_vector_status_valid),                           //    status.valid
		.status_data      (vic_vector_status_data),                            //          .data
		.clk              (clk_clk),                                           //       clk.clk
		.reset_n          (~clk_reset_reset),                                  // clk_reset.reset_n
		.dc_in_valid      (1'b0),                                              // (terminated)
		.dc_in_data       (45'b000000000000000000000000000000000000000000000), // (terminated)
		.dc_out_valid     (),                                                  // (terminated)
		.dc_out_data      (),                                                  // (terminated)
		.out32_valid      (),                                                  // (terminated)
		.out32_data       ()                                                   // (terminated)
	);

	altera_vic_priority #(
		.NUMBER_OF_INT_PORTS (32),
		.PRIORITY_WIDTH      (6),
		.DATA_WIDTH          (19)
	) vic_priority (
		.clk        (clk_clk),                 //       clk.clk
		.reset_n    (~clk_reset_reset),        // clk_reset.reset_n
		.in0_valid  (vic_csr_out0_valid),      //       in0.valid
		.in0_data   (vic_csr_out0_data),       //          .data
		.in1_valid  (vic_csr_out1_valid),      //       in1.valid
		.in1_data   (vic_csr_out1_data),       //          .data
		.in2_valid  (vic_csr_out2_valid),      //       in2.valid
		.in2_data   (vic_csr_out2_data),       //          .data
		.in3_valid  (vic_csr_out3_valid),      //       in3.valid
		.in3_data   (vic_csr_out3_data),       //          .data
		.in4_valid  (vic_csr_out4_valid),      //       in4.valid
		.in4_data   (vic_csr_out4_data),       //          .data
		.in5_valid  (vic_csr_out5_valid),      //       in5.valid
		.in5_data   (vic_csr_out5_data),       //          .data
		.in6_valid  (vic_csr_out6_valid),      //       in6.valid
		.in6_data   (vic_csr_out6_data),       //          .data
		.in7_valid  (vic_csr_out7_valid),      //       in7.valid
		.in7_data   (vic_csr_out7_data),       //          .data
		.in8_valid  (vic_csr_out8_valid),      //       in8.valid
		.in8_data   (vic_csr_out8_data),       //          .data
		.in9_valid  (vic_csr_out9_valid),      //       in9.valid
		.in9_data   (vic_csr_out9_data),       //          .data
		.in10_valid (vic_csr_out10_valid),     //      in10.valid
		.in10_data  (vic_csr_out10_data),      //          .data
		.in11_valid (vic_csr_out11_valid),     //      in11.valid
		.in11_data  (vic_csr_out11_data),      //          .data
		.in12_valid (vic_csr_out12_valid),     //      in12.valid
		.in12_data  (vic_csr_out12_data),      //          .data
		.in13_valid (vic_csr_out13_valid),     //      in13.valid
		.in13_data  (vic_csr_out13_data),      //          .data
		.in14_valid (vic_csr_out14_valid),     //      in14.valid
		.in14_data  (vic_csr_out14_data),      //          .data
		.in15_valid (vic_csr_out15_valid),     //      in15.valid
		.in15_data  (vic_csr_out15_data),      //          .data
		.in16_valid (vic_csr_out16_valid),     //      in16.valid
		.in16_data  (vic_csr_out16_data),      //          .data
		.in17_valid (vic_csr_out17_valid),     //      in17.valid
		.in17_data  (vic_csr_out17_data),      //          .data
		.in18_valid (vic_csr_out18_valid),     //      in18.valid
		.in18_data  (vic_csr_out18_data),      //          .data
		.in19_valid (vic_csr_out19_valid),     //      in19.valid
		.in19_data  (vic_csr_out19_data),      //          .data
		.in20_valid (vic_csr_out20_valid),     //      in20.valid
		.in20_data  (vic_csr_out20_data),      //          .data
		.in21_valid (vic_csr_out21_valid),     //      in21.valid
		.in21_data  (vic_csr_out21_data),      //          .data
		.in22_valid (vic_csr_out22_valid),     //      in22.valid
		.in22_data  (vic_csr_out22_data),      //          .data
		.in23_valid (vic_csr_out23_valid),     //      in23.valid
		.in23_data  (vic_csr_out23_data),      //          .data
		.in24_valid (vic_csr_out24_valid),     //      in24.valid
		.in24_data  (vic_csr_out24_data),      //          .data
		.in25_valid (vic_csr_out25_valid),     //      in25.valid
		.in25_data  (vic_csr_out25_data),      //          .data
		.in26_valid (vic_csr_out26_valid),     //      in26.valid
		.in26_data  (vic_csr_out26_data),      //          .data
		.in27_valid (vic_csr_out27_valid),     //      in27.valid
		.in27_data  (vic_csr_out27_data),      //          .data
		.in28_valid (vic_csr_out28_valid),     //      in28.valid
		.in28_data  (vic_csr_out28_data),      //          .data
		.in29_valid (vic_csr_out29_valid),     //      in29.valid
		.in29_data  (vic_csr_out29_data),      //          .data
		.in30_valid (vic_csr_out30_valid),     //      in30.valid
		.in30_data  (vic_csr_out30_data),      //          .data
		.in31_valid (vic_csr_out31_valid),     //      in31.valid
		.in31_data  (vic_csr_out31_data),      //          .data
		.pri_valid  (vic_priority_out_valid),  //       out.valid
		.pri_data   (vic_priority_out_data),   //          .data
		.in32_valid (1'b0),                    // (terminated)
		.in32_data  (19'b0000000000000000000)  // (terminated)
	);

	altera_vic_vector #(
		.DAISY_CHAIN_ENABLE (0)
	) vic_vector (
		.clk           (clk_clk),                              //       clk.clk
		.reset_n       (~clk_reset_reset),                     // clk_reset.reset_n
		.in_valid      (vic_priority_out_valid),               //        in.valid
		.in_data       (vic_priority_out_data),                //          .data
		.control_valid (vic_csr_control_valid),                //   control.valid
		.control_data  (vic_csr_control_data),                 //          .data
		.status_valid  (vic_vector_status_valid),              //    status.valid
		.status_data   (vic_vector_status_data),               //          .data
		.out_valid     (interrupt_controller_out_valid),       //       out.valid
		.out_data      (interrupt_controller_out_data),        //          .data
		.dc_valid      (1'b0),                                 // (terminated)
		.dc_data       (32'b00000000000000000000000000000000)  // (terminated)
	);

endmodule
