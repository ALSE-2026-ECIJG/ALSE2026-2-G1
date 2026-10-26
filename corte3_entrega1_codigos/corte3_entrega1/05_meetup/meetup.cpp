#include "meetup.h"

namespace meetup {

scheduler::scheduler(boost::gregorian::months_of_year month, int year)
    : m_month(month), m_year(year) {}

boost::gregorian::date scheduler::teenth(boost::gregorian::greg_weekday day) const {
    for (int day_num = 13; day_num <= 19; ++day_num) {
        boost::gregorian::date d(m_year, m_month, day_num);
        if (d.day_of_week() == day) {
            return d;
        }
    }
    return boost::gregorian::date(boost::gregorian::not_a_date_time);
}

boost::gregorian::date scheduler::find_nth(boost::gregorian::greg_weekday day, int n) const {
    int count = 0;
    boost::gregorian::date d(m_year, m_month, 1);
    while (d.month() == m_month) {
        if (d.day_of_week() == day) {
            count++;
            if (count == n) {
                return d;
            }
        }
        d += boost::gregorian::date_duration(1);
    }
    return boost::gregorian::date(boost::gregorian::not_a_date_time);
}

boost::gregorian::date scheduler::last_day(boost::gregorian::greg_weekday day) const {
    boost::gregorian::date d(m_year, m_month, 1);
    d = d.end_of_month();
    while (d.month() == m_month) {
        if (d.day_of_week() == day) {
            return d;
        }
        d -= boost::gregorian::date_duration(1);
    }
    return boost::gregorian::date(boost::gregorian::not_a_date_time);
}

boost::gregorian::date scheduler::monteenth() const { return teenth(boost::gregorian::Monday); }
boost::gregorian::date scheduler::tuesteenth() const { return teenth(boost::gregorian::Tuesday); }
boost::gregorian::date scheduler::wednesteenth() const { return teenth(boost::gregorian::Wednesday); }
boost::gregorian::date scheduler::thursteenth() const { return teenth(boost::gregorian::Thursday); }
boost::gregorian::date scheduler::friteenth() const { return teenth(boost::gregorian::Friday); }
boost::gregorian::date scheduler::saturteenth() const { return teenth(boost::gregorian::Saturday); }
boost::gregorian::date scheduler::sunteenth() const { return teenth(boost::gregorian::Sunday); }

boost::gregorian::date scheduler::first_monday() const { return find_nth(boost::gregorian::Monday, 1); }
boost::gregorian::date scheduler::first_tuesday() const { return find_nth(boost::gregorian::Tuesday, 1); }
boost::gregorian::date scheduler::first_wednesday() const { return find_nth(boost::gregorian::Wednesday, 1); }
boost::gregorian::date scheduler::first_thursday() const { return find_nth(boost::gregorian::Thursday, 1); }
boost::gregorian::date scheduler::first_friday() const { return find_nth(boost::gregorian::Friday, 1); }
boost::gregorian::date scheduler::first_saturday() const { return find_nth(boost::gregorian::Saturday, 1); }
boost::gregorian::date scheduler::first_sunday() const { return find_nth(boost::gregorian::Sunday, 1); }

boost::gregorian::date scheduler::second_monday() const { return find_nth(boost::gregorian::Monday, 2); }
boost::gregorian::date scheduler::second_tuesday() const { return find_nth(boost::gregorian::Tuesday, 2); }
boost::gregorian::date scheduler::second_wednesday() const { return find_nth(boost::gregorian::Wednesday, 2); }
boost::gregorian::date scheduler::second_thursday() const { return find_nth(boost::gregorian::Thursday, 2); }
boost::gregorian::date scheduler::second_friday() const { return find_nth(boost::gregorian::Friday, 2); }
boost::gregorian::date scheduler::second_saturday() const { return find_nth(boost::gregorian::Saturday, 2); }
boost::gregorian::date scheduler::second_sunday() const { return find_nth(boost::gregorian::Sunday, 2); }

boost::gregorian::date scheduler::third_monday() const { return find_nth(boost::gregorian::Monday, 3); }
boost::gregorian::date scheduler::third_tuesday() const { return find_nth(boost::gregorian::Tuesday, 3); }
boost::gregorian::date scheduler::third_wednesday() const { return find_nth(boost::gregorian::Wednesday, 3); }
boost::gregorian::date scheduler::third_thursday() const { return find_nth(boost::gregorian::Thursday, 3); }
boost::gregorian::date scheduler::third_friday() const { return find_nth(boost::gregorian::Friday, 3); }
boost::gregorian::date scheduler::third_saturday() const { return find_nth(boost::gregorian::Saturday, 3); }
boost::gregorian::date scheduler::third_sunday() const { return find_nth(boost::gregorian::Sunday, 3); }

boost::gregorian::date scheduler::fourth_monday() const { return find_nth(boost::gregorian::Monday, 4); }
boost::gregorian::date scheduler::fourth_tuesday() const { return find_nth(boost::gregorian::Tuesday, 4); }
boost::gregorian::date scheduler::fourth_wednesday() const { return find_nth(boost::gregorian::Wednesday, 4); }
boost::gregorian::date scheduler::fourth_thursday() const { return find_nth(boost::gregorian::Thursday, 4); }
boost::gregorian::date scheduler::fourth_friday() const { return find_nth(boost::gregorian::Friday, 4); }
boost::gregorian::date scheduler::fourth_saturday() const { return find_nth(boost::gregorian::Saturday, 4); }
boost::gregorian::date scheduler::fourth_sunday() const { return find_nth(boost::gregorian::Sunday, 4); }

boost::gregorian::date scheduler::last_monday() const { return last_day(boost::gregorian::Monday); }
boost::gregorian::date scheduler::last_tuesday() const { return last_day(boost::gregorian::Tuesday); }
boost::gregorian::date scheduler::last_wednesday() const { return last_day(boost::gregorian::Wednesday); }
boost::gregorian::date scheduler::last_thursday() const { return last_day(boost::gregorian::Thursday); }
boost::gregorian::date scheduler::last_friday() const { return last_day(boost::gregorian::Friday); }
boost::gregorian::date scheduler::last_saturday() const { return last_day(boost::gregorian::Saturday); }
boost::gregorian::date scheduler::last_sunday() const { return last_day(boost::gregorian::Sunday); }

}  // namespace meetup
