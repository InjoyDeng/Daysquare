//
//  DAYCalendarView.h
//  Daysquare
//
//  Created by 杨弘宇 on 16/6/7.
//  Copyright © 2016年 Cyandev. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EventKit/EventKit.h>

@class DAYCalendarView;
@protocol DAYCalendarViewDelegate <NSObject>

@optional
- (BOOL)calendarView:(DAYCalendarView *)calendarView shouldChangeSelecteDate:(NSDate *)newDate;
- (UIColor *)calendarView:(DAYCalendarView *)calendarView drawComponentTextColorOfDate:(NSDate *)date;

@end

@interface DAYCalendarView : UIControl

@property (copy, nonatomic) NSDate *selectedDate;

@property (weak, nonatomic) id<DAYCalendarViewDelegate> delegate;

@property (copy, nonatomic) NSArray<NSString *> *localizedStringsOfWeekday;

// Appearance settings:
@property (copy, nonatomic) UIColor *weekdayHeaderTextColor;
@property (copy, nonatomic) UIColor *weekdayHeaderWeekendTextColor;
@property (copy, nonatomic) UIColor *componentTextColor;
@property (copy, nonatomic) UIColor *highlightedComponentTextColor;
@property (copy, nonatomic) UIColor *selectedIndicatorColor;
@property (copy, nonatomic) UIColor *todayIndicatorColor;

@property (assign, nonatomic) CGFloat weekdayHeaderFontSize;
@property (assign, nonatomic) CGFloat componentFontSize;

@property (assign, nonatomic) CGFloat indicatorRadius;

@property (assign, nonatomic) BOOL boldPrimaryComponentText;
@property (assign, nonatomic) BOOL singleRowMode;
@property (assign, nonatomic) BOOL useTodayAnotherName;
@property (assign, nonatomic) BOOL onlyVisibleCurrentMonth;

// Additional features:
@property (assign, nonatomic) BOOL showUserEvents;

- (void)reloadViewAnimated:(BOOL)animated;   // Invalidate the original view, use it after changing the appearance settings.

- (void)jumpToNextMonth;
- (void)jumpToPreviousMonth;
- (void)jumpToMonth:(NSUInteger)month year:(NSUInteger)year;

@end
