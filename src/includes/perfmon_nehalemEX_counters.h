/*
 * =======================================================================================
 *
 *      Filename:  perfmon_nehalemEX_counters.h
 *
 *      Description: Counter Header File of perfmon module for Intel Westmere EX.
 *
 *      Version:   5.1
 *      Released:  16.11.2020
 *
 *      Author:   Jan Treibig (jt), jan.treibig@gmail.com
 *                Thomas Gruber (tr), thomas.roehl@googlemail.com
 *      Project:  likwid
 *
 *      Copyright (C) 2015 RRZE, University Erlangen-Nuremberg
 *
 *      This program is free software: you can redistribute it and/or modify it under
 *      the terms of the GNU General Public License as published by the Free Software
 *      Foundation, either version 3 of the License, or (at your option) any later
 *      version.
 *
 *      This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *      WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *      PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along with
 *      this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =======================================================================================
 */

#define NUM_COUNTERS_CORE_NEHALEMEX 7
#define NUM_COUNTERS_UNCORE_NEHALEMEX 105
#define NUM_COUNTERS_NEHALEMEX 105

#define NEX_VALID_OPTIONS_FIXED EVENT_OPTION_COUNT_KERNEL_MASK|EVENT_OPTION_ANYTHREAD_MASK
#define NEX_VALID_OPTIONS_PMC EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_COUNT_KERNEL_MASK|EVENT_OPTION_THRESHOLD_MASK

#define NEX_VALID_OPTIONS_MBOX EVENT_OPTION_MATCH0_MASK|EVENT_OPTION_MASK0_MASK
#define NEX_VALID_OPTIONS_BBOX EVENT_OPTION_MATCH0_MASK|EVENT_OPTION_MASK0_MASK
#define NEX_VALID_OPTIONS_CBOX EVENT_OPTION_THRESHOLD_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_EDGE_MASK
#define NEX_VALID_OPTIONS_SBOX EVENT_OPTION_THRESHOLD_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_EDGE_MASK
#define NEX_VALID_OPTIONS_WBOX EVENT_OPTION_THRESHOLD_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_EDGE_MASK

static RegisterMap nehalemEX_counter_map[NUM_COUNTERS_NEHALEMEX] = {
    /* Fixed Counters: instructions retired, cycles unhalted core */
    {"FIXC0", PMC0, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR0, 0, 0, NEX_VALID_OPTIONS_FIXED},
    {"FIXC1", PMC1, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR1, 0, 0, NEX_VALID_OPTIONS_FIXED},
    {"FIXC2", PMC2, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR2, 0, 0, NEX_VALID_OPTIONS_FIXED},
    /* PMC Counters: 4 48bit wide */
    {"PMC0", PMC3, PMC, MSR_PERFEVTSEL0, MSR_PMC0, 0, 0, NEX_VALID_OPTIONS_PMC},
    {"PMC1", PMC4, PMC, MSR_PERFEVTSEL1, MSR_PMC1, 0, 0, NEX_VALID_OPTIONS_PMC},
    {"PMC2", PMC5, PMC, MSR_PERFEVTSEL2, MSR_PMC2, 0, 0, NEX_VALID_OPTIONS_PMC},
    {"PMC3", PMC6, PMC, MSR_PERFEVTSEL3, MSR_PMC3, 0, 0, NEX_VALID_OPTIONS_PMC},
    /* MBOX */
    {"MBOX0C0",PMC7, MBOX0, MSR_M0_PMON_EVNT_SEL0, MSR_M0_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_MBOX},
    {"MBOX0C1",PMC8, MBOX0, MSR_M0_PMON_EVNT_SEL1, MSR_M0_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_MBOX},
    {"MBOX0C2",PMC9, MBOX0, MSR_M0_PMON_EVNT_SEL2, MSR_M0_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_MBOX},
    {"MBOX0C3",PMC10, MBOX0, MSR_M0_PMON_EVNT_SEL3, MSR_M0_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_MBOX},
    {"MBOX0C4",PMC11, MBOX0, MSR_M0_PMON_EVNT_SEL4, MSR_M0_PMON_CTR4, 0, 0, NEX_VALID_OPTIONS_MBOX},
    {"MBOX0C5",PMC12, MBOX0, MSR_M0_PMON_EVNT_SEL5, MSR_M0_PMON_CTR5, 0, 0, NEX_VALID_OPTIONS_MBOX},
    {"MBOX1C0",PMC13, MBOX1, MSR_M1_PMON_EVNT_SEL0, MSR_M1_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_MBOX},
    {"MBOX1C1",PMC14, MBOX1, MSR_M1_PMON_EVNT_SEL1, MSR_M1_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_MBOX},
    {"MBOX1C2",PMC15, MBOX1, MSR_M1_PMON_EVNT_SEL2, MSR_M1_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_MBOX},
    {"MBOX1C3",PMC16, MBOX1, MSR_M1_PMON_EVNT_SEL3, MSR_M1_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_MBOX},
    {"MBOX1C4",PMC17, MBOX1, MSR_M1_PMON_EVNT_SEL4, MSR_M1_PMON_CTR4, 0, 0, NEX_VALID_OPTIONS_MBOX},
    {"MBOX1C5",PMC18, MBOX1, MSR_M1_PMON_EVNT_SEL5, MSR_M1_PMON_CTR5, 0, 0, NEX_VALID_OPTIONS_MBOX},
    /* BBOX */
    {"BBOX0C0",PMC19, BBOX0, MSR_B0_PMON_EVNT_SEL0, MSR_B0_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_BBOX},
    {"BBOX0C1",PMC20, BBOX0, MSR_B0_PMON_EVNT_SEL1, MSR_B0_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_BBOX},
    {"BBOX0C2",PMC21, BBOX0, MSR_B0_PMON_EVNT_SEL2, MSR_B0_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_BBOX},
    {"BBOX0C3",PMC22, BBOX0, MSR_B0_PMON_EVNT_SEL3, MSR_B0_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_BBOX},
    {"BBOX1C0",PMC23, BBOX1, MSR_B1_PMON_EVNT_SEL0, MSR_B1_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_BBOX},
    {"BBOX1C1",PMC24, BBOX1, MSR_B1_PMON_EVNT_SEL1, MSR_B1_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_BBOX},
    {"BBOX1C2",PMC25, BBOX1, MSR_B1_PMON_EVNT_SEL2, MSR_B1_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_BBOX},
    {"BBOX1C3",PMC26, BBOX1, MSR_B1_PMON_EVNT_SEL3, MSR_B1_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_BBOX},
    /* RBOX */
    {"RBOX0C0",PMC27, RBOX0, MSR_R0_PMON_EVNT_SEL0, MSR_R0_PMON_CTR0, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX0C1",PMC28, RBOX0, MSR_R0_PMON_EVNT_SEL1, MSR_R0_PMON_CTR1, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX0C2",PMC29, RBOX0, MSR_R0_PMON_EVNT_SEL2, MSR_R0_PMON_CTR2, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX0C3",PMC30, RBOX0, MSR_R0_PMON_EVNT_SEL3, MSR_R0_PMON_CTR3, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX0C4",PMC31, RBOX0, MSR_R0_PMON_EVNT_SEL4, MSR_R0_PMON_CTR4, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX0C5",PMC32, RBOX0, MSR_R0_PMON_EVNT_SEL5, MSR_R0_PMON_CTR5, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX0C6",PMC33, RBOX0, MSR_R0_PMON_EVNT_SEL6, MSR_R0_PMON_CTR6, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX0C7",PMC34, RBOX0, MSR_R0_PMON_EVNT_SEL7, MSR_R0_PMON_CTR7, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX1C0",PMC35, RBOX1, MSR_R1_PMON_EVNT_SEL8, MSR_R1_PMON_CTR8, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX1C1",PMC36, RBOX1, MSR_R1_PMON_EVNT_SEL9, MSR_R1_PMON_CTR9, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX1C2",PMC37, RBOX1, MSR_R1_PMON_EVNT_SEL10, MSR_R1_PMON_CTR10, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX1C3",PMC38, RBOX1, MSR_R1_PMON_EVNT_SEL11, MSR_R1_PMON_CTR11, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX1C4",PMC39, RBOX1, MSR_R1_PMON_EVNT_SEL12, MSR_R1_PMON_CTR12, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX1C5",PMC40, RBOX1, MSR_R1_PMON_EVNT_SEL13, MSR_R1_PMON_CTR13, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX1C6",PMC41, RBOX1, MSR_R1_PMON_EVNT_SEL14, MSR_R1_PMON_CTR14, 0, 0, EVENT_OPTION_NONE_MASK},
    {"RBOX1C7",PMC42, RBOX1, MSR_R1_PMON_EVNT_SEL15, MSR_R1_PMON_CTR15, 0, 0, EVENT_OPTION_NONE_MASK},
    /* WBOX */
    {"WBOX0",PMC43, WBOX, MSR_W_PMON_EVNT_SEL0, MSR_W_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_WBOX},
    {"WBOX1",PMC44, WBOX, MSR_W_PMON_EVNT_SEL1, MSR_W_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_WBOX},
    {"WBOX2",PMC45, WBOX, MSR_W_PMON_EVNT_SEL2, MSR_W_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_WBOX},
    {"WBOX3",PMC46, WBOX, MSR_W_PMON_EVNT_SEL3, MSR_W_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_WBOX},
    {"WBOXFIX",PMC47, WBOX0FIX, MSR_W_PMON_FIXED_CTR_CTL, MSR_W_PMON_FIXED_CTR, 0, 0, EVENT_OPTION_NONE_MASK},
    /* UBOX */
    {"UBOX0",PMC48, UBOX, MSR_U_PMON_GLOBAL_EVNT_SEL, MSR_U_PMON_GLOBAL_CTR, 0, 0, EVENT_OPTION_EDGE_MASK},
    /* CBOXes */
    {"CBOX0C0",PMC49, CBOX0, MSR_C0_PMON_EVNT_SEL0, MSR_C0_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX0C1",PMC50, CBOX0, MSR_C0_PMON_EVNT_SEL1, MSR_C0_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX0C2",PMC51, CBOX0, MSR_C0_PMON_EVNT_SEL2, MSR_C0_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX0C3",PMC52, CBOX0, MSR_C0_PMON_EVNT_SEL3, MSR_C0_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX0C4",PMC53, CBOX0, MSR_C0_PMON_EVNT_SEL4, MSR_C0_PMON_CTR4, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX0C5",PMC54, CBOX0, MSR_C0_PMON_EVNT_SEL5, MSR_C0_PMON_CTR5, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX1C0",PMC55, CBOX1, MSR_C1_PMON_EVNT_SEL0, MSR_C1_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX1C1",PMC56, CBOX1, MSR_C1_PMON_EVNT_SEL1, MSR_C1_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX1C2",PMC57, CBOX1, MSR_C1_PMON_EVNT_SEL2, MSR_C1_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX1C3",PMC58, CBOX1, MSR_C1_PMON_EVNT_SEL3, MSR_C1_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX1C4",PMC59, CBOX1, MSR_C1_PMON_EVNT_SEL4, MSR_C1_PMON_CTR4, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX1C5",PMC60, CBOX1, MSR_C1_PMON_EVNT_SEL5, MSR_C1_PMON_CTR5, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX2C0",PMC61, CBOX2, MSR_C2_PMON_EVNT_SEL0, MSR_C2_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX2C1",PMC62, CBOX2, MSR_C2_PMON_EVNT_SEL1, MSR_C2_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX2C2",PMC63, CBOX2, MSR_C2_PMON_EVNT_SEL2, MSR_C2_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX2C3",PMC64, CBOX2, MSR_C2_PMON_EVNT_SEL3, MSR_C2_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX2C4",PMC65, CBOX2, MSR_C2_PMON_EVNT_SEL4, MSR_C2_PMON_CTR4, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX2C5",PMC66, CBOX2, MSR_C2_PMON_EVNT_SEL5, MSR_C2_PMON_CTR5, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX3C0",PMC67, CBOX3, MSR_C3_PMON_EVNT_SEL0, MSR_C3_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX3C1",PMC68, CBOX3, MSR_C3_PMON_EVNT_SEL1, MSR_C3_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX3C2",PMC69, CBOX3, MSR_C3_PMON_EVNT_SEL2, MSR_C3_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX3C3",PMC70, CBOX3, MSR_C3_PMON_EVNT_SEL3, MSR_C3_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX3C4",PMC71, CBOX3, MSR_C3_PMON_EVNT_SEL4, MSR_C3_PMON_CTR4, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX3C5",PMC72, CBOX3, MSR_C3_PMON_EVNT_SEL5, MSR_C3_PMON_CTR5, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX4C0",PMC73, CBOX4, MSR_C4_PMON_EVNT_SEL0, MSR_C4_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX4C1",PMC74, CBOX4, MSR_C4_PMON_EVNT_SEL1, MSR_C4_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX4C2",PMC75, CBOX4, MSR_C4_PMON_EVNT_SEL2, MSR_C4_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX4C3",PMC76, CBOX4, MSR_C4_PMON_EVNT_SEL3, MSR_C4_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX4C4",PMC77, CBOX4, MSR_C4_PMON_EVNT_SEL4, MSR_C4_PMON_CTR4, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX4C5",PMC78, CBOX4, MSR_C4_PMON_EVNT_SEL5, MSR_C4_PMON_CTR5, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX5C0",PMC79, CBOX5, MSR_C5_PMON_EVNT_SEL0, MSR_C5_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX5C1",PMC80, CBOX5, MSR_C5_PMON_EVNT_SEL1, MSR_C5_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX5C2",PMC81, CBOX5, MSR_C5_PMON_EVNT_SEL2, MSR_C5_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX5C3",PMC82, CBOX5, MSR_C5_PMON_EVNT_SEL3, MSR_C5_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX5C4",PMC83, CBOX5, MSR_C5_PMON_EVNT_SEL4, MSR_C5_PMON_CTR4, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX5C5",PMC84, CBOX5, MSR_C5_PMON_EVNT_SEL5, MSR_C5_PMON_CTR5, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX6C0",PMC85, CBOX6, MSR_C6_PMON_EVNT_SEL0, MSR_C6_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX6C1",PMC86, CBOX6, MSR_C6_PMON_EVNT_SEL1, MSR_C6_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX6C2",PMC87, CBOX6, MSR_C6_PMON_EVNT_SEL2, MSR_C6_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX6C3",PMC88, CBOX6, MSR_C6_PMON_EVNT_SEL3, MSR_C6_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX6C4",PMC89, CBOX6, MSR_C6_PMON_EVNT_SEL4, MSR_C6_PMON_CTR4, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX6C4",PMC90, CBOX6, MSR_C6_PMON_EVNT_SEL5, MSR_C6_PMON_CTR5, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX7C0",PMC91, CBOX7, MSR_C7_PMON_EVNT_SEL0, MSR_C7_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX7C1",PMC92, CBOX7, MSR_C7_PMON_EVNT_SEL1, MSR_C7_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX7C2",PMC93, CBOX7, MSR_C7_PMON_EVNT_SEL2, MSR_C7_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX7C3",PMC94, CBOX7, MSR_C7_PMON_EVNT_SEL3, MSR_C7_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX7C4",PMC95, CBOX7, MSR_C7_PMON_EVNT_SEL4, MSR_C7_PMON_CTR4, 0, 0, NEX_VALID_OPTIONS_CBOX},
    {"CBOX7C5",PMC96, CBOX7, MSR_C7_PMON_EVNT_SEL5, MSR_C7_PMON_CTR5, 0, 0, NEX_VALID_OPTIONS_CBOX},
    /* SBOXes */
    {"SBOX0C0",PMC97, SBOX0, MSR_S0_PMON_EVNT_SEL0, MSR_S0_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_SBOX},
    {"SBOX0C1",PMC98, SBOX0, MSR_S0_PMON_EVNT_SEL1, MSR_S0_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_SBOX},
    {"SBOX0C2",PMC99, SBOX0, MSR_S0_PMON_EVNT_SEL2, MSR_S0_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_SBOX},
    {"SBOX0C3",PMC100, SBOX0, MSR_S0_PMON_EVNT_SEL3, MSR_S0_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_SBOX},
    {"SBOX1C0",PMC101, SBOX1, MSR_S1_PMON_EVNT_SEL0, MSR_S1_PMON_CTR0, 0, 0, NEX_VALID_OPTIONS_SBOX},
    {"SBOX1C1",PMC102, SBOX1, MSR_S1_PMON_EVNT_SEL1, MSR_S1_PMON_CTR1, 0, 0, NEX_VALID_OPTIONS_SBOX},
    {"SBOX1C2",PMC103, SBOX1, MSR_S1_PMON_EVNT_SEL2, MSR_S1_PMON_CTR2, 0, 0, NEX_VALID_OPTIONS_SBOX},
    {"SBOX1C3",PMC104, SBOX1, MSR_S1_PMON_EVNT_SEL3, MSR_S1_PMON_CTR3, 0, 0, NEX_VALID_OPTIONS_SBOX}
};


static BoxMap nehalemEX_box_map[NUM_UNITS] = {
    [PMC] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, 0, 0, 0, 48},
    [FIXED] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, 0, 0, 0, 48},
    [MBOX0] = {MSR_M0_PMON_BOX_CTRL, MSR_M0_PMON_BOX_STATUS, MSR_M0_PMON_BOX_OVF_CTRL, 0, 0, 0, 48, MSR_M0_PMON_ADDR_MATCH, MSR_M0_PMON_ADDR_MASK},
    [MBOX1] = {MSR_M1_PMON_BOX_CTRL, MSR_M1_PMON_BOX_STATUS, MSR_M1_PMON_BOX_OVF_CTRL, 0, 0, 0, 48, MSR_M1_PMON_ADDR_MATCH, MSR_M1_PMON_ADDR_MASK},
    [BBOX0] = {MSR_B0_PMON_BOX_CTRL, MSR_B0_PMON_BOX_STATUS, MSR_B0_PMON_BOX_OVF_CTRL, 0, 0, 0, 48, MSR_B0_PMON_MATCH,MSR_B0_PMON_MASK},
    [BBOX1] = {MSR_B1_PMON_BOX_CTRL, MSR_B1_PMON_BOX_STATUS, MSR_B1_PMON_BOX_OVF_CTRL, 0, 0, 0, 48, MSR_B1_PMON_MATCH,MSR_B1_PMON_MASK},
    [RBOX0] = {MSR_R0_PMON_BOX_CTRL, MSR_R0_PMON_BOX_STATUS, MSR_R0_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [RBOX1] = {MSR_R1_PMON_BOX_CTRL, MSR_R1_PMON_BOX_STATUS, MSR_R1_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [SBOX0] = {MSR_S0_PMON_BOX_CTRL, MSR_S0_PMON_BOX_STATUS, MSR_S0_PMON_BOX_OVF_CTRL, 0, 0, 0, 48, MSR_S0_PMON_MATCH, MSR_S0_PMON_MASK},
    [SBOX1] = {MSR_S1_PMON_BOX_CTRL, MSR_S1_PMON_BOX_STATUS, MSR_S1_PMON_BOX_OVF_CTRL, 0, 0, 0, 48, MSR_S1_PMON_MATCH, MSR_S1_PMON_MASK},
    [CBOX0] = {MSR_C0_PMON_BOX_CTRL, MSR_C0_PMON_BOX_STATUS, MSR_C0_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [CBOX1] = {MSR_C1_PMON_BOX_CTRL, MSR_C1_PMON_BOX_STATUS, MSR_C1_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [CBOX2] = {MSR_C2_PMON_BOX_CTRL, MSR_C2_PMON_BOX_STATUS, MSR_C2_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [CBOX3] = {MSR_C3_PMON_BOX_CTRL, MSR_C3_PMON_BOX_STATUS, MSR_C3_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [CBOX4] = {MSR_C4_PMON_BOX_CTRL, MSR_C4_PMON_BOX_STATUS, MSR_C4_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [CBOX5] = {MSR_C5_PMON_BOX_CTRL, MSR_C5_PMON_BOX_STATUS, MSR_C5_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [CBOX6] = {MSR_C6_PMON_BOX_CTRL, MSR_C6_PMON_BOX_STATUS, MSR_C6_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [CBOX7] = {MSR_C7_PMON_BOX_CTRL, MSR_C7_PMON_BOX_STATUS, MSR_C7_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [WBOX] = {MSR_W_PMON_BOX_CTRL, MSR_W_PMON_BOX_STATUS, MSR_W_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [WBOX0FIX] = {MSR_W_PMON_BOX_CTRL, MSR_W_PMON_BOX_STATUS, MSR_W_PMON_BOX_OVF_CTRL, 0, 0, 0, 48},
    [UBOX] = {MSR_U_PMON_GLOBAL_CTRL, MSR_U_PMON_GLOBAL_STATUS, MSR_U_PMON_GLOBAL_OVF_CTRL, 0, 0, 0, 48},
};
