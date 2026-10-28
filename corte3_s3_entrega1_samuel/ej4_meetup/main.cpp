#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Meetup {
public:
    int findDay(int year, int month, string week, string weekday) {
        // Mapeo de días de la semana (0 = Domingo, 1 = Lunes, ..., 6 = Sábado)
        int targetWeekday = 0;
        if (weekday == "Sunday") targetWeekday = 0;
        else if (weekday == "Monday") targetWeekday = 1;
        else if (weekday == "Tuesday") targetWeekday = 2;
        else if (weekday == "Wednesday") targetWeekday = 3;
        else if (weekday == "Thursday") targetWeekday = 4;
        else if (weekday == "Friday") targetWeekday = 5;
        else if (weekday == "Saturday") targetWeekday = 6;

        // Obtener el primer día del mes (día de la semana)
        tm time_in = { 0, 0, 0, 1, month - 1, year - 1900 };
        time_t time_temp = mktime(&time_in);
        tm *time_out = localtime(&time_temp);
        int firstDayOfMonth = time_out->tm_wday; // 0 = Domingo

        // Calcular cuántos días sumar para llegar al primer "weekday" del mes
        int dayOffset = (targetWeekday - firstDayOfMonth + 7) % 7;
        int firstOccurrence = 1 + dayOffset;

        if (week == "first") {
            return firstOccurrence;
        } else if (week == "second") {
            return firstOccurrence + 7;
        } else if (week == "third") {
            return firstOccurrence + 14;
        } else if (week == "fourth") {
            return firstOccurrence + 21;
        } else if (week == "teenth") {
            int day = firstOccurrence;
            while (day < 13) day += 7;
            return day;
        } else if (week == "last") {
            // Encontrar el último día del mes
            tm nextMonth = { 0, 0, 0, 1, month, year - 1900 };
            time_t nextMonthTime = mktime(&nextMonth);
            tm *nextMonthOut = localtime(&nextMonthTime);
            
            int lastDayOfMonth;
            // Restar un día al primer día del siguiente mes
            if (month == 12) {
                lastDayOfMonth = 31; // Diciembre siempre tiene 31
            } else {
                // Truco: ir al día 0 del siguiente mes = último día del mes actual
                tm lastDay = { 0, 0, 0, 0, month, year - 1900 };
                time_t lastDayTime = mktime(&lastDay);
                tm *lastDayOut = localtime(&lastDayTime);
                lastDayOfMonth = lastDayOut->tm_mday;
            }

            int lastWeekday = lastDayOfMonth - ((lastDayOfMonth - targetWeekday + firstDayOfMonth) % 7 + 7) % 7;
            
            // Ajuste para que caiga en el día correcto
            while (lastWeekday > 0) {
                tm temp = { 0, 0, 0, lastWeekday, month - 1, year - 1900 };
                time_t tempTime = mktime(&temp);
                tm *tempOut = localtime(&tempTime);
                if (tempOut->tm_wday == targetWeekday) {
                    return lastWeekday;
                }
                lastWeekday--;
            }
        }
        return -1; // Error
    }
};

int main() {
    Meetup meetup;

    cout << "--- Simulacion Meetup (Exercism) ---" << endl;
    
    cout << "Primer lunes de enero 2018: " << meetup.findDay(2018, 1, "first", "Monday") << " (Esperado: 1)" << endl;
    cout << "Tercer martes de agosto 2019: " << meetup.findDay(2019, 8, "third", "Tuesday") << " (Esperado: 20)" << endl;
    cout << "Teenth miercoles de mayo 2020: " << meetup.findDay(2020, 5, "teenth", "Wednesday") << " (Esperado: 13)" << endl;
    cout << "Cuarto domingo de julio 2021: " << meetup.findDay(2021, 7, "fourth", "Sunday") << " (Esperado: 25)" << endl;
    cout << "Ultimo jueves de noviembre 2022: " << meetup.findDay(2022, 11, "last", "Thursday") << " (Esperado: 24)" << endl;
    cout << "Teenth sabado de agosto 1953: " << meetup.findDay(1953, 8, "teenth", "Saturday") << " (Esperado: 15)" << endl;

    return 0;
}
