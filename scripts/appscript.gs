function doGet(e) {
  var cal = CalendarApp.getCalendarsByName('epd_calendar')[0];      // use epd_calendar (change the calendar name or use the below)
  // var cal = CalendarApp.getDefaultCalendar();                    // use default calendar
  // var cal = CalendarApp.getCalendarById('example@gmail.com');    // use by ID

  if (!cal) {
    return ContentService.createTextOutput(JSON.stringify({ error: "No access to calendar" }))
           .setMimeType(ContentService.MimeType.JSON);
  }

  const now = new Date();
  var start = new Date(); start.setHours(0, 0, 0);  
  const oneday = 24 * 3600000; 
  const stop = new Date(start.getTime() + 14 * oneday); // 14 days to scan
  
  var events = cal.getEvents(start, stop);
  var eventList = [];

  for (var ii = 0; ii < events.length; ii++) {
    var event = events[ii];    

    eventList.push({
      startTime: Utilities.formatDate(event.getStartTime(), Session.getScriptTimeZone(), "HH:mm"), // HH:mm format
      endTime: Utilities.formatDate(event.getEndTime(), Session.getScriptTimeZone(), "HH:mm"),     // HH:mm format 
      description: event.getDescription().toString(),
      title: event.getTitle(),
      allDay: event.isAllDayEvent(),
      status: 0,
      alert: event.getEmailReminders(),
      month: Utilities.formatDate(event.getStartTime(), Session.getScriptTimeZone(), "M"), // 1–12
      day: Utilities.formatDate(event.getStartTime(), Session.getScriptTimeZone(), "d"),  // 1–31
      weekday: Utilities.formatDate(event.getStartTime(), Session.getScriptTimeZone(), "u") // 1=Monday, 7=Saturday
    });
  }

  return ContentService.createTextOutput(JSON.stringify({ events: eventList }))
         .setMimeType(ContentService.MimeType.JSON);
}
