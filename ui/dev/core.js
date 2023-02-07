/******/ (() => { // webpackBootstrap
var __webpack_exports__ = {};
/*!************************!*\
  !*** ./ui-src/core.js ***!
  \************************/
try {
  window.HTMLIFrameElement = function () {};
  window.setTimeout = function (callback) {
    var time = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 1;
    var timer = app.timer();
    timer.interval = time;
    timer.singleShot = true;
    timer.timeout.connect(this, callback);
    timer.start();
    return timer;
  };
  window.setInterval = function (callback) {
    var time = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 1;
    var timer = app.timer();
    timer.interval = time;
    timer.singleShot = false;
    timer.timeout.connect(this, callback);
    timer.start();
    return timer;
  };
  window.clearTimeout = function (timer) {
    app.deleteObject(timer);
  };
  au3.execute = function (name) {
    for (var _len = arguments.length, args = new Array(_len > 1 ? _len - 1 : 0), _key = 1; _key < _len; _key++) {
      args[_key - 1] = arguments[_key];
    }
    au3.call(name, args);
  };
} catch (error) {
  console.log(error.stack);
}
/******/ })()
;
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoiZGV2L2NvcmUuanMiLCJtYXBwaW5ncyI6Ijs7Ozs7QUFBQSxJQUFJO0VBQ0hBLE1BQU0sQ0FBQ0MsaUJBQWlCLEdBQUcsWUFBVSxDQUFDLENBQUM7RUFDdkNELE1BQU0sQ0FBQ0UsVUFBVSxHQUFHLFVBQVVDLFFBQVEsRUFBWTtJQUFBLElBQVZDLElBQUksdUVBQUcsQ0FBQztJQUMvQyxJQUFNQyxLQUFLLEdBQUdDLEdBQUcsQ0FBQ0QsS0FBSyxFQUFFO0lBQ3pCQSxLQUFLLENBQUNFLFFBQVEsR0FBR0gsSUFBSTtJQUNyQkMsS0FBSyxDQUFDRyxVQUFVLEdBQUcsSUFBSTtJQUN2QkgsS0FBSyxDQUFDSSxPQUFPLENBQUNDLE9BQU8sQ0FBQyxJQUFJLEVBQUVQLFFBQVEsQ0FBQztJQUNyQ0UsS0FBSyxDQUFDTSxLQUFLLEVBQUU7SUFDYixPQUFPTixLQUFLO0VBQ2IsQ0FBQztFQUVETCxNQUFNLENBQUNZLFdBQVcsR0FBRyxVQUFVVCxRQUFRLEVBQVk7SUFBQSxJQUFWQyxJQUFJLHVFQUFHLENBQUM7SUFDaEQsSUFBTUMsS0FBSyxHQUFHQyxHQUFHLENBQUNELEtBQUssRUFBRTtJQUN6QkEsS0FBSyxDQUFDRSxRQUFRLEdBQUdILElBQUk7SUFDckJDLEtBQUssQ0FBQ0csVUFBVSxHQUFHLEtBQUs7SUFDeEJILEtBQUssQ0FBQ0ksT0FBTyxDQUFDQyxPQUFPLENBQUMsSUFBSSxFQUFFUCxRQUFRLENBQUM7SUFDckNFLEtBQUssQ0FBQ00sS0FBSyxFQUFFO0lBQ2IsT0FBT04sS0FBSztFQUNiLENBQUM7RUFFREwsTUFBTSxDQUFDYSxZQUFZLEdBQUcsVUFBVVIsS0FBSyxFQUFFO0lBQ3RDQyxHQUFHLENBQUNRLFlBQVksQ0FBQ1QsS0FBSyxDQUFDO0VBQ3hCLENBQUM7RUFDRFUsR0FBRyxDQUFDQyxPQUFPLEdBQUcsVUFBU0MsSUFBSSxFQUFVO0lBQUEsa0NBQUxDLElBQUk7TUFBSkEsSUFBSTtJQUFBO0lBQ25DSCxHQUFHLENBQUNJLElBQUksQ0FBQ0YsSUFBSSxFQUFFQyxJQUFJLENBQUM7RUFDckIsQ0FBQztBQUNGLENBQUMsQ0FBQyxPQUFPRSxLQUFLLEVBQUU7RUFDZkMsT0FBTyxDQUFDQyxHQUFHLENBQUNGLEtBQUssQ0FBQ0csS0FBSyxDQUFDO0FBQ3pCLEMiLCJzb3VyY2VzIjpbIndlYnBhY2s6Ly9xdC1yZWFjdC8uL3VpLXNyYy9jb3JlLmpzIl0sInNvdXJjZXNDb250ZW50IjpbInRyeSB7XHJcblx0d2luZG93LkhUTUxJRnJhbWVFbGVtZW50ID0gZnVuY3Rpb24oKXt9XHJcblx0d2luZG93LnNldFRpbWVvdXQgPSBmdW5jdGlvbiAoY2FsbGJhY2ssIHRpbWUgPSAxKSB7XHJcblx0XHRjb25zdCB0aW1lciA9IGFwcC50aW1lcigpXHJcblx0XHR0aW1lci5pbnRlcnZhbCA9IHRpbWVcclxuXHRcdHRpbWVyLnNpbmdsZVNob3QgPSB0cnVlXHJcblx0XHR0aW1lci50aW1lb3V0LmNvbm5lY3QodGhpcywgY2FsbGJhY2spO1xyXG5cdFx0dGltZXIuc3RhcnQoKTtcclxuXHRcdHJldHVybiB0aW1lclxyXG5cdH1cclxuXHJcblx0d2luZG93LnNldEludGVydmFsID0gZnVuY3Rpb24gKGNhbGxiYWNrLCB0aW1lID0gMSkge1xyXG5cdFx0Y29uc3QgdGltZXIgPSBhcHAudGltZXIoKVxyXG5cdFx0dGltZXIuaW50ZXJ2YWwgPSB0aW1lXHJcblx0XHR0aW1lci5zaW5nbGVTaG90ID0gZmFsc2VcclxuXHRcdHRpbWVyLnRpbWVvdXQuY29ubmVjdCh0aGlzLCBjYWxsYmFjayk7XHJcblx0XHR0aW1lci5zdGFydCgpO1xyXG5cdFx0cmV0dXJuIHRpbWVyXHJcblx0fVxyXG5cclxuXHR3aW5kb3cuY2xlYXJUaW1lb3V0ID0gZnVuY3Rpb24gKHRpbWVyKSB7XHJcblx0XHRhcHAuZGVsZXRlT2JqZWN0KHRpbWVyKVxyXG5cdH1cclxuXHRhdTMuZXhlY3V0ZSA9IGZ1bmN0aW9uKG5hbWUsIC4uLmFyZ3Mpe1xyXG5cdFx0YXUzLmNhbGwobmFtZSwgYXJncylcclxuXHR9XHJcbn0gY2F0Y2ggKGVycm9yKSB7XHJcblx0Y29uc29sZS5sb2coZXJyb3Iuc3RhY2spXHJcbn1cclxuIl0sIm5hbWVzIjpbIndpbmRvdyIsIkhUTUxJRnJhbWVFbGVtZW50Iiwic2V0VGltZW91dCIsImNhbGxiYWNrIiwidGltZSIsInRpbWVyIiwiYXBwIiwiaW50ZXJ2YWwiLCJzaW5nbGVTaG90IiwidGltZW91dCIsImNvbm5lY3QiLCJzdGFydCIsInNldEludGVydmFsIiwiY2xlYXJUaW1lb3V0IiwiZGVsZXRlT2JqZWN0IiwiYXUzIiwiZXhlY3V0ZSIsIm5hbWUiLCJhcmdzIiwiY2FsbCIsImVycm9yIiwiY29uc29sZSIsImxvZyIsInN0YWNrIl0sInNvdXJjZVJvb3QiOiIifQ==