/*
 * =======================================================================================
 *
 *      Filename:  perfmon_broadwelld_counters.h
 *
 *      Description:  Counter Header File of perfmon module for Broadwell D.
 *
 *      Version:   5.1
 *      Released:  16.11.2020
 *
 *      Author:   Thomas Gruber (tr), thomas.roehl@googlemail.com
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


#define NUM_COUNTERS_BROADWELLD 146
#define NUM_COUNTERS_CORE_BROADWELLD 13
#define NUM_COUNTERS_UNCORE_BROADWELLD 85

#define BDW_D_VALID_OPTIONS_FIXED EVENT_OPTION_ANYTHREAD_MASK|EVENT_OPTION_COUNT_KERNEL_MASK
#define BDW_D_VALID_OPTIONS_PMC EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK|EVENT_OPTION_INVERT_MASK| \
            EVENT_OPTION_ANYTHREAD_MASK|EVENT_OPTION_IN_TRANS_MASK|EVENT_OPTION_THRESHOLD_MASK
#define BDW_D_VALID_OPTIONS_UBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK|EVENT_OPTION_INVERT_MASK
#define BDW_D_VALID_OPTIONS_CBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK|\
            EVENT_OPTION_TID_MASK|EVENT_OPTION_NID_MASK|EVENT_OPTION_OPCODE_MASK|EVENT_OPTION_STATE_MASK|\
            EVENT_OPTION_MATCH0_MASK
#define BDW_D_VALID_OPTIONS_WBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK|\
            EVENT_OPTION_OCCUPANCY_MASK|EVENT_OPTION_OCCUPANCY_FILTER_MASK|EVENT_OPTION_OCCUPANCY_EDGE_MASK|\
            EVENT_OPTION_OCCUPANCY_INVERT_MASK
#define BDW_D_VALID_OPTIONS_BBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK
#define BDW_D_VALID_OPTIONS_MBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK
#define BDW_D_VALID_OPTIONS_IBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK
#define BDW_D_VALID_OPTIONS_PBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK

static RegisterMap broadwelld_counter_map[NUM_COUNTERS_BROADWELLD] = {
    /* Fixed Counters: instructions retired, cycles unhalted core */
    {"FIXC0", PMC0, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR0, 0, 0, BDW_D_VALID_OPTIONS_FIXED},
    {"FIXC1", PMC1, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR1, 0, 0, BDW_D_VALID_OPTIONS_FIXED},
    {"FIXC2", PMC2, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR2, 0, 0, BDW_D_VALID_OPTIONS_FIXED},
    /* PMC Counters: 4 48bit wide */
    {"PMC0", PMC3, PMC, MSR_PERFEVTSEL0, MSR_PMC0, 0, 0, BDW_D_VALID_OPTIONS_PMC},
    {"PMC1", PMC4, PMC, MSR_PERFEVTSEL1, MSR_PMC1, 0, 0, BDW_D_VALID_OPTIONS_PMC},
    {"PMC2", PMC5, PMC, MSR_PERFEVTSEL2, MSR_PMC2, 0, 0, BDW_D_VALID_OPTIONS_PMC|EVENT_OPTION_IN_TRANS_ABORT_MASK},
    {"PMC3", PMC6, PMC, MSR_PERFEVTSEL3, MSR_PMC3, 0, 0, BDW_D_VALID_OPTIONS_PMC},
    /* Additional PMC Counters: 4 48bit wide if HyperThreading is disabled*/
    {"PMC4", PMC7, PMC, MSR_PERFEVTSEL4, MSR_PMC4, 0, 0, BDW_D_VALID_OPTIONS_PMC},
    {"PMC5", PMC8, PMC, MSR_PERFEVTSEL5, MSR_PMC5, 0, 0, BDW_D_VALID_OPTIONS_PMC},
    {"PMC6", PMC9, PMC, MSR_PERFEVTSEL6, MSR_PMC6, 0, 0, BDW_D_VALID_OPTIONS_PMC|EVENT_OPTION_IN_TRANS_ABORT_MASK},
    {"PMC7", PMC10, PMC, MSR_PERFEVTSEL7, MSR_PMC7, 0, 0, BDW_D_VALID_OPTIONS_PMC},
    /* Temperature Sensor*/
    {"TMP0", PMC11, THERMAL, 0, IA32_THERM_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    /* Vcore Status*/
    {"VTG0", PMC12, VOLTAGE, 0, MSR_PERF_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    /* RAPL counters */
    {"PWR0", PMC13, POWER, 0, MSR_PKG_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR1", PMC14, POWER, 0, MSR_PP0_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR2", PMC15, POWER, 0, MSR_PP1_ENERGY_STATUS,  0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR3", PMC16, POWER, 0, MSR_DRAM_ENERGY_STATUS,  0, 0, EVENT_OPTION_NONE_MASK},
    {"UBOX0", PMC17, UBOX, MSR_UNC_V3_U_PMON_CTL0, MSR_UNC_V3_U_PMON_CTR0,  0, 0, BDW_D_VALID_OPTIONS_UBOX},
    {"UBOX1", PMC18, UBOX, MSR_UNC_V3_U_PMON_CTL1, MSR_UNC_V3_U_PMON_CTR1,  0, 0, BDW_D_VALID_OPTIONS_UBOX},
    {"UBOXFIX", PMC19, UBOXFIX, MSR_UNC_V3_U_UCLK_FIXED_CTL, MSR_UNC_V3_U_UCLK_FIXED_CTR, 0, 0, EVENT_OPTION_NONE_MASK},
    {"CBOX0C0", PMC20, CBOX0, MSR_UNC_V3_C0_PMON_CTL0, MSR_UNC_V3_C0_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX0C1", PMC21, CBOX0, MSR_UNC_V3_C0_PMON_CTL1, MSR_UNC_V3_C0_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX0C2", PMC22, CBOX0, MSR_UNC_V3_C0_PMON_CTL2, MSR_UNC_V3_C0_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX0C3", PMC23, CBOX0, MSR_UNC_V3_C0_PMON_CTL3, MSR_UNC_V3_C0_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX1C0", PMC24, CBOX1, MSR_UNC_V3_C1_PMON_CTL0, MSR_UNC_V3_C1_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX1C1", PMC25, CBOX1, MSR_UNC_V3_C1_PMON_CTL1, MSR_UNC_V3_C1_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX1C2", PMC26, CBOX1, MSR_UNC_V3_C1_PMON_CTL2, MSR_UNC_V3_C1_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX1C3", PMC27, CBOX1, MSR_UNC_V3_C1_PMON_CTL3, MSR_UNC_V3_C1_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX2C0", PMC28, CBOX2, MSR_UNC_V3_C2_PMON_CTL0, MSR_UNC_V3_C2_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX2C1", PMC29, CBOX2, MSR_UNC_V3_C2_PMON_CTL1, MSR_UNC_V3_C2_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX2C2", PMC30, CBOX2, MSR_UNC_V3_C2_PMON_CTL2, MSR_UNC_V3_C2_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX2C3", PMC31, CBOX2, MSR_UNC_V3_C2_PMON_CTL3, MSR_UNC_V3_C2_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX3C0", PMC32, CBOX3, MSR_UNC_V3_C3_PMON_CTL0, MSR_UNC_V3_C3_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX3C1", PMC33, CBOX3, MSR_UNC_V3_C3_PMON_CTL1, MSR_UNC_V3_C3_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX3C2", PMC34, CBOX3, MSR_UNC_V3_C3_PMON_CTL2, MSR_UNC_V3_C3_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX3C3", PMC35, CBOX3, MSR_UNC_V3_C3_PMON_CTL3, MSR_UNC_V3_C3_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX4C0", PMC36, CBOX4, MSR_UNC_V3_C4_PMON_CTL0, MSR_UNC_V3_C4_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX4C1", PMC37, CBOX4, MSR_UNC_V3_C4_PMON_CTL1, MSR_UNC_V3_C4_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX4C2", PMC38, CBOX4, MSR_UNC_V3_C4_PMON_CTL2, MSR_UNC_V3_C4_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX4C3", PMC39, CBOX4, MSR_UNC_V3_C4_PMON_CTL3, MSR_UNC_V3_C4_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX5C0", PMC40, CBOX5, MSR_UNC_V3_C5_PMON_CTL0, MSR_UNC_V3_C5_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX5C1", PMC41, CBOX5, MSR_UNC_V3_C5_PMON_CTL1, MSR_UNC_V3_C5_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX5C2", PMC42, CBOX5, MSR_UNC_V3_C5_PMON_CTL2, MSR_UNC_V3_C5_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX5C3", PMC43, CBOX5, MSR_UNC_V3_C5_PMON_CTL3, MSR_UNC_V3_C5_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX6C0", PMC44, CBOX6, MSR_UNC_V3_C6_PMON_CTL0, MSR_UNC_V3_C6_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX6C1", PMC45, CBOX6, MSR_UNC_V3_C6_PMON_CTL1, MSR_UNC_V3_C6_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX6C2", PMC46, CBOX6, MSR_UNC_V3_C6_PMON_CTL2, MSR_UNC_V3_C6_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX6C3", PMC47, CBOX6, MSR_UNC_V3_C6_PMON_CTL3, MSR_UNC_V3_C6_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX7C0", PMC48, CBOX7, MSR_UNC_V3_C7_PMON_CTL0, MSR_UNC_V3_C7_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX7C1", PMC49, CBOX7, MSR_UNC_V3_C7_PMON_CTL1, MSR_UNC_V3_C7_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX7C2", PMC50, CBOX7, MSR_UNC_V3_C7_PMON_CTL2, MSR_UNC_V3_C7_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX7C3", PMC51, CBOX7, MSR_UNC_V3_C7_PMON_CTL3, MSR_UNC_V3_C7_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX8C0", PMC52, CBOX8, MSR_UNC_V3_C8_PMON_CTL0, MSR_UNC_V3_C8_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX8C1", PMC53, CBOX8, MSR_UNC_V3_C8_PMON_CTL1, MSR_UNC_V3_C8_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX8C2", PMC54, CBOX8, MSR_UNC_V3_C8_PMON_CTL2, MSR_UNC_V3_C8_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX8C3", PMC55, CBOX8, MSR_UNC_V3_C8_PMON_CTL3, MSR_UNC_V3_C8_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX9C0", PMC56, CBOX9, MSR_UNC_V3_C9_PMON_CTL0, MSR_UNC_V3_C9_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX9C1", PMC57, CBOX9, MSR_UNC_V3_C9_PMON_CTL1, MSR_UNC_V3_C9_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX9C2", PMC58, CBOX9, MSR_UNC_V3_C9_PMON_CTL2, MSR_UNC_V3_C9_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX9C3", PMC59, CBOX9, MSR_UNC_V3_C9_PMON_CTL3, MSR_UNC_V3_C9_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX10C0", PMC60, CBOX10, MSR_UNC_V3_C10_PMON_CTL0, MSR_UNC_V3_C10_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX10C1", PMC61, CBOX10, MSR_UNC_V3_C10_PMON_CTL1, MSR_UNC_V3_C10_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX10C2", PMC62, CBOX10, MSR_UNC_V3_C10_PMON_CTL2, MSR_UNC_V3_C10_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX10C3", PMC63, CBOX10, MSR_UNC_V3_C10_PMON_CTL3, MSR_UNC_V3_C10_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX11C0", PMC64, CBOX11, MSR_UNC_V3_C11_PMON_CTL0, MSR_UNC_V3_C11_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX11C1", PMC65, CBOX11, MSR_UNC_V3_C11_PMON_CTL1, MSR_UNC_V3_C11_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX11C2", PMC66, CBOX11, MSR_UNC_V3_C11_PMON_CTL2, MSR_UNC_V3_C11_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX11C3", PMC67, CBOX11, MSR_UNC_V3_C11_PMON_CTL3, MSR_UNC_V3_C11_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX12C0", PMC68, CBOX12, MSR_UNC_V3_C12_PMON_CTL0, MSR_UNC_V3_C12_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX12C1", PMC69, CBOX12, MSR_UNC_V3_C12_PMON_CTL1, MSR_UNC_V3_C12_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX12C2", PMC70, CBOX12, MSR_UNC_V3_C12_PMON_CTL2, MSR_UNC_V3_C12_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX12C3", PMC71, CBOX12, MSR_UNC_V3_C12_PMON_CTL3, MSR_UNC_V3_C12_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX13C0", PMC72, CBOX13, MSR_UNC_V3_C13_PMON_CTL0, MSR_UNC_V3_C13_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX13C1", PMC73, CBOX13, MSR_UNC_V3_C13_PMON_CTL1, MSR_UNC_V3_C13_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX13C2", PMC74, CBOX13, MSR_UNC_V3_C13_PMON_CTL2, MSR_UNC_V3_C13_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX13C3", PMC75, CBOX13, MSR_UNC_V3_C13_PMON_CTL3, MSR_UNC_V3_C13_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX14C0", PMC76, CBOX14, MSR_UNC_V3_C14_PMON_CTL0, MSR_UNC_V3_C14_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX14C1", PMC77, CBOX14, MSR_UNC_V3_C14_PMON_CTL1, MSR_UNC_V3_C14_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX14C2", PMC78, CBOX14, MSR_UNC_V3_C14_PMON_CTL2, MSR_UNC_V3_C14_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX14C3", PMC79, CBOX14, MSR_UNC_V3_C14_PMON_CTL3, MSR_UNC_V3_C14_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX15C0", PMC80, CBOX15, MSR_UNC_V3_C15_PMON_CTL0, MSR_UNC_V3_C15_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX15C1", PMC81, CBOX15, MSR_UNC_V3_C15_PMON_CTL1, MSR_UNC_V3_C15_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX15C2", PMC82, CBOX15, MSR_UNC_V3_C15_PMON_CTL2, MSR_UNC_V3_C15_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"CBOX15C3", PMC83, CBOX15, MSR_UNC_V3_C15_PMON_CTL3, MSR_UNC_V3_C15_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_CBOX},
    {"WBOX0", PMC84, WBOX, MSR_UNC_V3_PCU_PMON_CTL0, MSR_UNC_V3_PCU_PMON_CTR0, 0, 0, BDW_D_VALID_OPTIONS_WBOX},
    {"WBOX1", PMC85, WBOX, MSR_UNC_V3_PCU_PMON_CTL1, MSR_UNC_V3_PCU_PMON_CTR1, 0, 0, BDW_D_VALID_OPTIONS_WBOX},
    {"WBOX2", PMC86, WBOX, MSR_UNC_V3_PCU_PMON_CTL2, MSR_UNC_V3_PCU_PMON_CTR2, 0, 0, BDW_D_VALID_OPTIONS_WBOX},
    {"WBOX3", PMC87, WBOX, MSR_UNC_V3_PCU_PMON_CTL3, MSR_UNC_V3_PCU_PMON_CTR3, 0, 0, BDW_D_VALID_OPTIONS_WBOX},
    {"WBOX0FIX", PMC88, WBOX0FIX, 0, MSR_UNC_V3_PCU_CC3_CTR, 0, 0, EVENT_OPTION_NONE_MASK},
    {"WBOX1FIX", PMC89, WBOX0FIX, 0, MSR_UNC_V3_PCU_CC6_CTR, 0, 0, EVENT_OPTION_NONE_MASK},
    {"BBOX0C0", PMC90, BBOX0, PCI_UNC_HA_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE_0, BDW_D_VALID_OPTIONS_BBOX},
    {"BBOX0C1", PMC91, BBOX0, PCI_UNC_HA_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE_0, BDW_D_VALID_OPTIONS_BBOX},
    {"BBOX0C2", PMC92, BBOX0, PCI_UNC_HA_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE_0, BDW_D_VALID_OPTIONS_BBOX},
    {"BBOX0C3", PMC93, BBOX0, PCI_UNC_HA_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE_0, BDW_D_VALID_OPTIONS_BBOX},
    {"BBOX1C0", PMC94, BBOX1, PCI_UNC_HA_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE_1, BDW_D_VALID_OPTIONS_BBOX},
    {"BBOX1C1", PMC95, BBOX1, PCI_UNC_HA_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE_1, BDW_D_VALID_OPTIONS_BBOX},
    {"BBOX1C2", PMC96, BBOX1, PCI_UNC_HA_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE_1, BDW_D_VALID_OPTIONS_BBOX},
    {"BBOX1C3", PMC97, BBOX1, PCI_UNC_HA_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE_1, BDW_D_VALID_OPTIONS_BBOX},
    {"MBOX0C0", PMC98, MBOX0, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_0, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX0C1", PMC99, MBOX0, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_0, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX0C2", PMC100, MBOX0, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_0, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX0FIX", PMC101, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_INVERT_MASK},
    {"MBOX0C3", PMC102, MBOX0, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_0, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX1C0", PMC103, MBOX1, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_1, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX1C1", PMC104, MBOX1, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_1, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX1C2", PMC105, MBOX1, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_1, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX1C3", PMC106, MBOX1, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_1, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX1FIX", PMC107, MBOX1FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_1, EVENT_OPTION_INVERT_MASK},
    {"MBOX2C0", PMC108, MBOX2, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_2, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX2C1", PMC109, MBOX2, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_2, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX2C2", PMC110, MBOX2, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_2, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX2C3", PMC111, MBOX2, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_2, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX2FIX", PMC112, MBOX2FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_2, EVENT_OPTION_INVERT_MASK},
    {"MBOX3C0", PMC113, MBOX3, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_3, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX3C1", PMC114, MBOX3, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_3, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX3C2", PMC115, MBOX3, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_3, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX3C3", PMC116, MBOX3, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_3, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX3FIX", PMC117, MBOX3FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_3, EVENT_OPTION_INVERT_MASK},
    {"MBOX4C0", PMC118, MBOX4, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_0, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX4C1", PMC119, MBOX4, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_0, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX4C2", PMC120, MBOX4, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_0, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX4C3", PMC121, MBOX4, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_0, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX4FIX", PMC122, MBOX4FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_0, EVENT_OPTION_INVERT_MASK},
    {"MBOX5C0", PMC123, MBOX5, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_1, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX5C1", PMC124, MBOX5, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_1, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX5C2", PMC125, MBOX5, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_1, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX5C3", PMC126, MBOX5, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_1, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX5FIX", PMC127, MBOX5FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_1, EVENT_OPTION_INVERT_MASK},
    {"MBOX6C0", PMC128, MBOX6, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_2, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX6C1", PMC129, MBOX6, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_2, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX6C2", PMC130, MBOX6, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_2, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX6C3", PMC131, MBOX6, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_2, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX6FIX", PMC132, MBOX6FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_2, EVENT_OPTION_INVERT_MASK},
    {"MBOX7C0", PMC133, MBOX7, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_3, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX7C1", PMC134, MBOX7, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_3, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX7C2", PMC135, MBOX7, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_3, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX7C3", PMC136, MBOX7, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_3, BDW_D_VALID_OPTIONS_MBOX},
    {"MBOX7FIX", PMC137, MBOX7FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_3, EVENT_OPTION_INVERT_MASK},
    {"IBOX0C0", PMC138, IBOX0, PCI_UNC_IRP0_PMON_CTL_0, PCI_UNC_IRP0_PMON_CTR_0, 0, PCI_IRP_DEVICE, BDW_D_VALID_OPTIONS_IBOX},
    {"IBOX0C1", PMC139, IBOX0, PCI_UNC_IRP0_PMON_CTL_1, PCI_UNC_IRP0_PMON_CTR_1, 0, PCI_IRP_DEVICE, BDW_D_VALID_OPTIONS_IBOX},
    {"IBOX1C0", PMC140, IBOX1, PCI_UNC_IRP1_PMON_CTL_0, PCI_UNC_IRP1_PMON_CTR_0, 0, PCI_IRP_DEVICE, BDW_D_VALID_OPTIONS_IBOX},
    {"IBOX1C1", PMC141, IBOX1, PCI_UNC_IRP1_PMON_CTL_1, PCI_UNC_IRP1_PMON_CTR_1, 0, PCI_IRP_DEVICE, BDW_D_VALID_OPTIONS_IBOX},
    {"PBOX0", PMC142, PBOX, PCI_UNC_R2PCIE_PMON_CTL_0, PCI_UNC_R2PCIE_PMON_CTR_0_A, PCI_UNC_R2PCIE_PMON_CTR_0_B, PCI_R2PCIE_DEVICE, BDW_D_VALID_OPTIONS_PBOX},
    {"PBOX1", PMC143, PBOX, PCI_UNC_R2PCIE_PMON_CTL_1, PCI_UNC_R2PCIE_PMON_CTR_1_A, PCI_UNC_R2PCIE_PMON_CTR_1_B, PCI_R2PCIE_DEVICE, BDW_D_VALID_OPTIONS_PBOX},
    {"PBOX2", PMC144, PBOX, PCI_UNC_R2PCIE_PMON_CTL_2, PCI_UNC_R2PCIE_PMON_CTR_2_A, PCI_UNC_R2PCIE_PMON_CTR_2_B, PCI_R2PCIE_DEVICE, BDW_D_VALID_OPTIONS_PBOX},
    {"PBOX3", PMC145, PBOX, PCI_UNC_R2PCIE_PMON_CTL_3, PCI_UNC_R2PCIE_PMON_CTR_3_A, PCI_UNC_R2PCIE_PMON_CTR_3_B, PCI_R2PCIE_DEVICE, BDW_D_VALID_OPTIONS_PBOX},
};

static BoxMap broadwelld_box_map[NUM_UNITS] = {
    [PMC] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, 0, 0, 0, 48},
    [THERMAL] = {0, 0, 0, 0, 0, 0, 8},
    [VOLTAGE] = {0, 0, 0, 0, 0, 0, 16},
    [FIXED] =  {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, 0, 0, 0, 48},
    [POWER] = {0, 0, 0, 0, 0, 0, 32},
    [UBOX] = {0, MSR_UNC_V3_U_PMON_BOX_STATUS, MSR_UNC_V3_U_PMON_BOX_STATUS, 1, 0, 0, 48},
    [UBOXFIX] = {0, MSR_UNC_V3_U_PMON_BOX_STATUS, MSR_UNC_V3_U_PMON_BOX_STATUS, 0, 0, 0, 48},
    [CBOX0] = {MSR_UNC_V3_C0_PMON_BOX_CTL, MSR_UNC_V3_C0_PMON_BOX_STATUS, MSR_UNC_V3_C0_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C0_PMON_BOX_FILTER0, MSR_UNC_V3_C0_PMON_BOX_FILTER1},
    [CBOX1] = {MSR_UNC_V3_C1_PMON_BOX_CTL, MSR_UNC_V3_C1_PMON_BOX_STATUS, MSR_UNC_V3_C1_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C1_PMON_BOX_FILTER0, MSR_UNC_V3_C1_PMON_BOX_FILTER1},
    [CBOX2] = {MSR_UNC_V3_C2_PMON_BOX_CTL, MSR_UNC_V3_C2_PMON_BOX_STATUS, MSR_UNC_V3_C2_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C2_PMON_BOX_FILTER0, MSR_UNC_V3_C2_PMON_BOX_FILTER1},
    [CBOX3] = {MSR_UNC_V3_C3_PMON_BOX_CTL, MSR_UNC_V3_C3_PMON_BOX_STATUS, MSR_UNC_V3_C3_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C3_PMON_BOX_FILTER0, MSR_UNC_V3_C3_PMON_BOX_FILTER1},
    [CBOX4] = {MSR_UNC_V3_C4_PMON_BOX_CTL, MSR_UNC_V3_C4_PMON_BOX_STATUS, MSR_UNC_V3_C4_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C4_PMON_BOX_FILTER0, MSR_UNC_V3_C4_PMON_BOX_FILTER1},
    [CBOX5] = {MSR_UNC_V3_C5_PMON_BOX_CTL, MSR_UNC_V3_C5_PMON_BOX_STATUS, MSR_UNC_V3_C5_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C5_PMON_BOX_FILTER0, MSR_UNC_V3_C5_PMON_BOX_FILTER1},
    [CBOX6] = {MSR_UNC_V3_C6_PMON_BOX_CTL, MSR_UNC_V3_C6_PMON_BOX_STATUS, MSR_UNC_V3_C6_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C6_PMON_BOX_FILTER0, MSR_UNC_V3_C6_PMON_BOX_FILTER1},
    [CBOX7] = {MSR_UNC_V3_C7_PMON_BOX_CTL, MSR_UNC_V3_C7_PMON_BOX_STATUS, MSR_UNC_V3_C7_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C7_PMON_BOX_FILTER0, MSR_UNC_V3_C7_PMON_BOX_FILTER1},
    [CBOX8] = {MSR_UNC_V3_C8_PMON_BOX_CTL, MSR_UNC_V3_C8_PMON_BOX_STATUS, MSR_UNC_V3_C8_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C8_PMON_BOX_FILTER0, MSR_UNC_V3_C8_PMON_BOX_FILTER1},
    [CBOX9] = {MSR_UNC_V3_C9_PMON_BOX_CTL, MSR_UNC_V3_C9_PMON_BOX_STATUS, MSR_UNC_V3_C9_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C9_PMON_BOX_FILTER0, MSR_UNC_V3_C9_PMON_BOX_FILTER1},
    [CBOX10] = {MSR_UNC_V3_C10_PMON_BOX_CTL, MSR_UNC_V3_C10_PMON_BOX_STATUS, MSR_UNC_V3_C10_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C10_PMON_BOX_FILTER0, MSR_UNC_V3_C10_PMON_BOX_FILTER1},
    [CBOX11] = {MSR_UNC_V3_C11_PMON_BOX_CTL, MSR_UNC_V3_C11_PMON_BOX_STATUS, MSR_UNC_V3_C11_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C11_PMON_BOX_FILTER0, MSR_UNC_V3_C11_PMON_BOX_FILTER1},
    [CBOX12] = {MSR_UNC_V3_C12_PMON_BOX_CTL, MSR_UNC_V3_C12_PMON_BOX_STATUS, MSR_UNC_V3_C12_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C12_PMON_BOX_FILTER0, MSR_UNC_V3_C12_PMON_BOX_FILTER1},
    [CBOX13] = {MSR_UNC_V3_C13_PMON_BOX_CTL, MSR_UNC_V3_C13_PMON_BOX_STATUS, MSR_UNC_V3_C13_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C13_PMON_BOX_FILTER0, MSR_UNC_V3_C13_PMON_BOX_FILTER1},
    [CBOX14] = {MSR_UNC_V3_C14_PMON_BOX_CTL, MSR_UNC_V3_C14_PMON_BOX_STATUS, MSR_UNC_V3_C14_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C14_PMON_BOX_FILTER0, MSR_UNC_V3_C14_PMON_BOX_FILTER1},
    [CBOX15] = {MSR_UNC_V3_C15_PMON_BOX_CTL, MSR_UNC_V3_C15_PMON_BOX_STATUS, MSR_UNC_V3_C15_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C15_PMON_BOX_FILTER0, MSR_UNC_V3_C15_PMON_BOX_FILTER1},
    [WBOX] = {MSR_UNC_V3_PCU_PMON_BOX_CTL, MSR_UNC_V3_PCU_PMON_BOX_STATUS,MSR_UNC_V3_PCU_PMON_BOX_STATUS, 2, 0, 0, 48, MSR_UNC_V3_PCU_PMON_BOX_FILTER},
    [WBOX0FIX] = {0,0,0,-1,0,0,64},
    [BBOX0] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, 21, 1, PCI_HA_DEVICE_0, 48},
    [BBOX1] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, -1, 1, PCI_HA_DEVICE_1, 48},
    [MBOX0] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 23, 1, PCI_IMC_DEVICE_0_CH_0, 48},
    [MBOX1] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 23, 1, PCI_IMC_DEVICE_0_CH_1, 48},
    [MBOX2] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 23, 1, PCI_IMC_DEVICE_0_CH_2, 48},
    [MBOX3] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 23, 1, PCI_IMC_DEVICE_0_CH_3, 48},
    [MBOX4] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, -1, 1, PCI_IMC_DEVICE_1_CH_0, 48},
    [MBOX5] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, -1, 1, PCI_IMC_DEVICE_1_CH_1, 48},
    [MBOX6] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, -1, 1, PCI_IMC_DEVICE_1_CH_2, 48},
    [MBOX7] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, -1, 1, PCI_IMC_DEVICE_1_CH_3, 48},
    [IBOX0] = {PCI_UNC_IRP_PMON_BOX_CTL, PCI_UNC_IRP_PMON_BOX_STATUS, PCI_UNC_IRP_PMON_BOX_STATUS, 34, 1, PCI_IRP_DEVICE, 48},
    [IBOX1] = {PCI_UNC_IRP_PMON_BOX_CTL, PCI_UNC_IRP_PMON_BOX_STATUS, PCI_UNC_IRP_PMON_BOX_STATUS, 34, 1, PCI_IRP_DEVICE, 48},
    [PBOX] = {PCI_UNC_R2PCIE_PMON_BOX_CTL, PCI_UNC_R2PCIE_PMON_BOX_STATUS, PCI_UNC_R2PCIE_PMON_BOX_STATUS, 29, 1, PCI_R2PCIE_DEVICE, 48},
};

static PciDevice broadwelld_pci_devices[MAX_NUM_PCI_DEVICES] = {
 [PCI_HA_DEVICE_0] = {HA, "12.1", "PCI_HA_DEVICE_0", "BBOX0", 0x6F30},
 [PCI_HA_DEVICE_1] = {HA, "12.5", "PCI_HA_DEVICE_1", "BBOX1", 0x6F38},
 [PCI_IMC_DEVICE_0_CH_0] = {IMC, "14.0", "PCI_IMC_DEVICE_0_CH_0", "MBOX0", 0x6FB4},
 [PCI_IMC_DEVICE_0_CH_1] = {IMC, "14.1", "PCI_IMC_DEVICE_0_CH_1", "MBOX1", 0x6FB5},
 [PCI_IMC_DEVICE_0_CH_2] = {IMC, "15.0", "PCI_IMC_DEVICE_0_CH_2", "MBOX2", 0x6FB0},
 [PCI_IMC_DEVICE_0_CH_3] = {IMC, "15.1", "PCI_IMC_DEVICE_0_CH_3", "MBOX3", 0x6FB1},
 [PCI_IMC_DEVICE_1_CH_0] = {IMC, "17.0", "PCI_IMC_DEVICE_1_CH_0", "MBOX4", 0x6FD4},
 [PCI_IMC_DEVICE_1_CH_1] = {IMC, "17.1", "PCI_IMC_DEVICE_1_CH_1", "MBOX5", 0x6FD5},
 [PCI_IMC_DEVICE_1_CH_2] = {IMC, "18.0", "PCI_IMC_DEVICE_1_CH_2", "MBOX6", 0x6FD0},
 [PCI_IMC_DEVICE_1_CH_3] = {IMC, "18.1", "PCI_IMC_DEVICE_1_CH_3", "MBOX7", 0x6FD1},
 [PCI_IRP_DEVICE] = {IRP, "05.6", "PCI_IRP_DEVICE", "IBOX0", 0x6F39},
 [PCI_R2PCIE_DEVICE] = {R2PCIE, "10.1", "PCI_R2PCIE_DEVICE", "PBOX0", 0x6F34},
};
