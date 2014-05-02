/* drivers/gpu/vithar/kbase/src/platform/mali_kbase_dvfs.h
 *
 * Copyright 2011 by S.LSI. Samsung Electronics Inc.
 * San#24, Nongseo-Dong, Giheung-Gu, Yongin, Korea
 *
 * Samsung SoC Mali-T604 DVFS driver
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software FoundatIon.
 */


/**
 * @file mali_kbase_dvfs.h
 * DVFS
 */
#ifndef _KBASE_DVFS_H_
#define _KBASE_DVFS_H_

/* Frequency that DVFS clock frequency decisions should be made */
#define KBASE_PM_DVFS_FREQUENCY 	100

#define MALI_DVFS_DEBUG 			0
#define MALI_DVFS_START_MAX_STEP 	1


#ifdef CONFIG_MALI_T6XX_DVFS_LIMIT_450 /* @TOFDO: CONFIG_VITHAR_DVFS_LIMIT_450 */
#define	MALI_DVFS_STEP 6
#else
#define	MALI_DVFS_STEP 7
#endif

#define MALI_DVFS_KEEP_STAY_CNT 10
#define MALI_DVFS_TIME_INTERVAL mali_dvfs_time_interval
extern int mali_dvfs_time_interval;


#ifdef CONFIG_MALI_T6XX_DVFS
#define CONFIG_MALI_T6XX_FREQ_LOCK
#ifdef CONFIG_CPU_FREQ
#define MALI_DVFS_ASV_ENABLE
#endif
#endif

// time share for GPU clock level
typedef struct _time_in_state {
	unsigned int freq;
 	unsigned long long time;
} mali_time_in_state;

struct regulator *kbase_platform_get_regulator(void);
int kbase_platform_regulator_init(void);
int kbase_platform_regulator_disable(void);
int kbase_platform_regulator_enable(void);
int kbase_platform_get_default_voltage(struct device *dev, int *vol);
int kbase_platform_get_voltage(struct device *dev, int *vol);
int kbase_platform_set_voltage(struct device *dev, int vol);
void kbase_platform_dvfs_set_clock(kbase_device *kbdev, int freq);
int kbase_platform_dvfs_sprint_avs_table(char *buf);
int kbase_platform_dvfs_set(int enable);
void kbase_platform_dvfs_set_level(struct kbase_device *kbdev, int level);
int kbase_platform_dvfs_get_level(int freq);
void kbase_platform_dvfs_set_low_resolution(void);


#ifdef CONFIG_MALI_T6XX_DVFS
int kbase_platform_dvfs_init(struct kbase_device *dev);
void kbase_platform_dvfs_term(void);
int kbase_platform_dvfs_event(struct kbase_device *kbdev, u32 utilisation);
int kbase_platform_dvfs_get_control_status(void);
int kbase_platform_dvfs_set_control_status(int onoff);
int kbase_pm_get_dvfs_utilisation(kbase_device *kbdev);
int kbase_platform_dvfs_get_utilisation(void);
#endif /* CONFIG_MALI_T6XX_DVFS */


int mali_get_dvfs_current_level(void);
int mali_get_dvfs_upper_locked_freq(void);
int mali_get_dvfs_under_locked_freq(void);
int mali_dvfs_freq_lock(int level);
void mali_dvfs_freq_unlock(void);
int mali_dvfs_freq_under_lock(int level);
void mali_dvfs_freq_under_unlock(void);
#endif /* _KBASE_DVFS_H_ */
