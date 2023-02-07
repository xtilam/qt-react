/******/ (() => { // webpackBootstrap
/******/ 	"use strict";
/******/ 	var __webpack_modules__ = ({

/***/ "./ui-src/App.tsx":
/*!************************!*\
  !*** ./ui-src/App.tsx ***!
  \************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "App": () => (/* binding */ App),
/* harmony export */   "changeTitle": () => (/* binding */ changeTitle)
/* harmony export */ });
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! react */ "react");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _components_QButton__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ./components/QButton */ "./ui-src/components/QButton.tsx");
/* harmony import */ var _components_QWidget__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./components/QWidget */ "./ui-src/components/QWidget.tsx");
/* harmony import */ var _main__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./main */ "./ui-src/main.tsx");
function _slicedToArray(arr, i) { return _arrayWithHoles(arr) || _iterableToArrayLimit(arr, i) || _unsupportedIterableToArray(arr, i) || _nonIterableRest(); }
function _nonIterableRest() { throw new TypeError("Invalid attempt to destructure non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); }
function _unsupportedIterableToArray(o, minLen) { if (!o) return; if (typeof o === "string") return _arrayLikeToArray(o, minLen); var n = Object.prototype.toString.call(o).slice(8, -1); if (n === "Object" && o.constructor) n = o.constructor.name; if (n === "Map" || n === "Set") return Array.from(o); if (n === "Arguments" || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(n)) return _arrayLikeToArray(o, minLen); }
function _arrayLikeToArray(arr, len) { if (len == null || len > arr.length) len = arr.length; for (var i = 0, arr2 = new Array(len); i < len; i++) arr2[i] = arr[i]; return arr2; }
function _iterableToArrayLimit(arr, i) { var _i = null == arr ? null : "undefined" != typeof Symbol && arr[Symbol.iterator] || arr["@@iterator"]; if (null != _i) { var _s, _e, _x, _r, _arr = [], _n = !0, _d = !1; try { if (_x = (_i = _i.call(arr)).next, 0 === i) { if (Object(_i) !== _i) return; _n = !1; } else for (; !(_n = (_s = _x.call(_i)).done) && (_arr.push(_s.value), _arr.length !== i); _n = !0); } catch (err) { _d = !0, _e = err; } finally { try { if (!_n && null != _i["return"] && (_r = _i["return"](), Object(_r) !== _r)) return; } finally { if (_d) throw _e; } } return _arr; } }
function _arrayWithHoles(arr) { if (Array.isArray(arr)) return arr; }




var changeTitle = function changeTitle(title) {
  _main__WEBPACK_IMPORTED_MODULE_3__.defaultWindow.title = title;
};
var unit = 70;
function App() {
  var _useState = (0,react__WEBPACK_IMPORTED_MODULE_0__.useState)(8),
    _useState2 = _slicedToArray(_useState, 2),
    count = _useState2[0],
    setCount = _useState2[1];
  function onClick() {
    setCount(count + 1);
  }
  return /*#__PURE__*/React.createElement(React.Fragment, null, /*#__PURE__*/React.createElement(_components_QWidget__WEBPACK_IMPORTED_MODULE_2__.QWidget, {
    layout: "row"
  },  true && /*#__PURE__*/React.createElement(_components_QButton__WEBPACK_IMPORTED_MODULE_1__.QButton, null, "value: ".concat(count, " => ").concat(count * unit)), /*#__PURE__*/React.createElement(_components_QButton__WEBPACK_IMPORTED_MODULE_1__.QButton, {
    onClick: function onClick() {
      setCount(count + 1);
    }
  }, "increase"), /*#__PURE__*/React.createElement(_components_QButton__WEBPACK_IMPORTED_MODULE_1__.QButton, {
    onClick: function onClick() {
      setCount(count - 1);
    }
  }, "decrease"), /*#__PURE__*/React.createElement(_components_QButton__WEBPACK_IMPORTED_MODULE_1__.QButton, {
    onClick: function onClick() {
      au3.execute('click', count * unit);
    }
  }, "dump"), count % 2 && /*#__PURE__*/React.createElement(_components_QButton__WEBPACK_IMPORTED_MODULE_1__.QButton, null, "ucc"), /*#__PURE__*/React.createElement(_components_QButton__WEBPACK_IMPORTED_MODULE_1__.QButton, null, "dc"), /*#__PURE__*/React.createElement(_components_QWidget__WEBPACK_IMPORTED_MODULE_2__.QWidget, null)));
}
try {} catch (error) {
  console.log('error');
}

/***/ }),

/***/ "./ui-src/components/BaseWidget.tsx":
/*!******************************************!*\
  !*** ./ui-src/components/BaseWidget.tsx ***!
  \******************************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "makeWidgetComponent": () => (/* binding */ makeWidgetComponent)
/* harmony export */ });
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! react */ "react");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
function _typeof(obj) { "@babel/helpers - typeof"; return _typeof = "function" == typeof Symbol && "symbol" == typeof Symbol.iterator ? function (obj) { return typeof obj; } : function (obj) { return obj && "function" == typeof Symbol && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }, _typeof(obj); }
function _createForOfIteratorHelper(o, allowArrayLike) { var it = typeof Symbol !== "undefined" && o[Symbol.iterator] || o["@@iterator"]; if (!it) { if (Array.isArray(o) || (it = _unsupportedIterableToArray(o)) || allowArrayLike && o && typeof o.length === "number") { if (it) o = it; var i = 0; var F = function F() {}; return { s: F, n: function n() { if (i >= o.length) return { done: true }; return { done: false, value: o[i++] }; }, e: function e(_e) { throw _e; }, f: F }; } throw new TypeError("Invalid attempt to iterate non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); } var normalCompletion = true, didErr = false, err; return { s: function s() { it = it.call(o); }, n: function n() { var step = it.next(); normalCompletion = step.done; return step; }, e: function e(_e2) { didErr = true; err = _e2; }, f: function f() { try { if (!normalCompletion && it["return"] != null) it["return"](); } finally { if (didErr) throw err; } } }; }
function _unsupportedIterableToArray(o, minLen) { if (!o) return; if (typeof o === "string") return _arrayLikeToArray(o, minLen); var n = Object.prototype.toString.call(o).slice(8, -1); if (n === "Object" && o.constructor) n = o.constructor.name; if (n === "Map" || n === "Set") return Array.from(o); if (n === "Arguments" || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(n)) return _arrayLikeToArray(o, minLen); }
function _arrayLikeToArray(arr, len) { if (len == null || len > arr.length) len = arr.length; for (var i = 0, arr2 = new Array(len); i < len; i++) arr2[i] = arr[i]; return arr2; }
function ownKeys(object, enumerableOnly) { var keys = Object.keys(object); if (Object.getOwnPropertySymbols) { var symbols = Object.getOwnPropertySymbols(object); enumerableOnly && (symbols = symbols.filter(function (sym) { return Object.getOwnPropertyDescriptor(object, sym).enumerable; })), keys.push.apply(keys, symbols); } return keys; }
function _objectSpread(target) { for (var i = 1; i < arguments.length; i++) { var source = null != arguments[i] ? arguments[i] : {}; i % 2 ? ownKeys(Object(source), !0).forEach(function (key) { _defineProperty(target, key, source[key]); }) : Object.getOwnPropertyDescriptors ? Object.defineProperties(target, Object.getOwnPropertyDescriptors(source)) : ownKeys(Object(source)).forEach(function (key) { Object.defineProperty(target, key, Object.getOwnPropertyDescriptor(source, key)); }); } return target; }
function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, _toPropertyKey(descriptor.key), descriptor); } }
function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); Object.defineProperty(Constructor, "prototype", { writable: false }); return Constructor; }
function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function"); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, writable: true, configurable: true } }); Object.defineProperty(subClass, "prototype", { writable: false }); if (superClass) _setPrototypeOf(subClass, superClass); }
function _setPrototypeOf(o, p) { _setPrototypeOf = Object.setPrototypeOf ? Object.setPrototypeOf.bind() : function _setPrototypeOf(o, p) { o.__proto__ = p; return o; }; return _setPrototypeOf(o, p); }
function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _getPrototypeOf(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _getPrototypeOf(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _possibleConstructorReturn(this, result); }; }
function _possibleConstructorReturn(self, call) { if (call && (_typeof(call) === "object" || typeof call === "function")) { return call; } else if (call !== void 0) { throw new TypeError("Derived constructors may only return object or undefined"); } return _assertThisInitialized(self); }
function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }
function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }
function _getPrototypeOf(o) { _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf.bind() : function _getPrototypeOf(o) { return o.__proto__ || Object.getPrototypeOf(o); }; return _getPrototypeOf(o); }
function _defineProperty(obj, key, value) { key = _toPropertyKey(key); if (key in obj) { Object.defineProperty(obj, key, { value: value, enumerable: true, configurable: true, writable: true }); } else { obj[key] = value; } return obj; }
function _toPropertyKey(arg) { var key = _toPrimitive(arg, "string"); return _typeof(key) === "symbol" ? key : String(key); }
function _toPrimitive(input, hint) { if (_typeof(input) !== "object" || input === null) return input; var prim = input[Symbol.toPrimitive]; if (prim !== undefined) { var res = prim.call(input, hint || "default"); if (_typeof(res) !== "object") return res; throw new TypeError("@@toPrimitive must return a primitive value."); } return (hint === "string" ? String : Number)(input); }

var BaseWidget = /*#__PURE__*/function (_React$Component) {
  _inherits(BaseWidget, _React$Component);
  var _super = _createSuper(BaseWidget);
  function BaseWidget() {
    var _this;
    _classCallCheck(this, BaseWidget);
    for (var _len = arguments.length, args = new Array(_len), _key = 0; _key < _len; _key++) {
      args[_key] = arguments[_key];
    }
    _this = _super.call.apply(_super, [this].concat(args));
    _defineProperty(_assertThisInitialized(_this), "ref", /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default().createRef());
    _defineProperty(_assertThisInitialized(_this), "historySetEvt", {});
    return _this;
  }
  _createClass(BaseWidget, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      var props = this.props;
      this.setProps(props);
      if (props.hasOwnProperty('show')) {
        this.ref.current.show = props.show;
      } else {
        this.ref.current.show = true;
      }
    }
  }, {
    key: "componentDidUpdate",
    value: function componentDidUpdate(prevProps) {
      this.setProps(this.props, prevProps);
    }
  }, {
    key: "setProps",
    value: function setProps(newProps) {
      var oldProps = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
      var el = this.ref.current;
      var _ref = this.constructor,
        requireProperty = _ref.requireProperty,
        propertyInvalid = _ref.propertyInvalid,
        events = _ref.events,
        mapConvert = _ref.mapConvert,
        defaultValues = _ref.defaultValues;
      var newHistorySetEvt = {};
      // set require properties
      for (var property in requireProperty) {
        var newVal = void 0;
        if (newProps.hasOwnProperty(property)) {
          newVal = newProps[property] || defaultValues[property];
        } else {
          newVal = requireProperty[property];
        }
        if (el[property] === newVal) continue;
        el[property] = newVal;
      }
      // convert props
      for (var key in mapConvert) {
        var val = newProps[key] || defaultValues[key];
        var elProperty = mapConvert[key];
        if (el[elProperty] === val) continue;
        el[elProperty] = val;
      }
      // set properties
      for (var _property in newProps) {
        var _val = newProps[_property];
        if (propertyInvalid[_property]) {
          if (propertyInvalid[_property] === 4) {
            var connect = events[_property](el);
            if (typeof connect !== 'function') continue;
            if (this.historySetEvt[_property]) {
              var oldFunc = oldProps[_property];
              if (typeof _val === 'function') {
                if (oldFunc !== _val) {
                  connect.disconnect(oldFunc);
                  connect.connect(_val);
                }
                newHistorySetEvt[_property] = true;
              } else {
                connect.disconnect(oldFunc);
              }
            } else {
              if (typeof _val !== 'function') continue;
              connect.connect(_val);
              newHistorySetEvt[_property] = true;
            }
          }
          continue;
        }
        if (el[_property] === _val) continue;
        el[_property] = _val;
      }
      this.historySetEvt = newHistorySetEvt;
    }
  }, {
    key: "withChildRender",
    value: function withChildRender() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default().createElement(this.constructor.tagName, {
        ref: this.ref,
        children: this.props.children
      });
    }
  }, {
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default().createElement(this.constructor.tagName, {
        ref: this.ref
      });
    }
  }]);
  return BaseWidget;
}((react__WEBPACK_IMPORTED_MODULE_0___default().Component));
_defineProperty(BaseWidget, "tagName", "");
_defineProperty(BaseWidget, "propertyInvalid", {
  children: true
});
_defineProperty(BaseWidget, "requireProperty", {});
_defineProperty(BaseWidget, "events", {});
_defineProperty(BaseWidget, "mapConvert", {});
_defineProperty(BaseWidget, "defaultValues", {});
function makeWidgetComponent(info) {
  var classWidget = /*#__PURE__*/function (_BaseWidget) {
    _inherits(classWidget, _BaseWidget);
    var _super2 = _createSuper(classWidget);
    function classWidget() {
      _classCallCheck(this, classWidget);
      return _super2.apply(this, arguments);
    }
    return _createClass(classWidget);
  }(BaseWidget);
  classWidget.tagName = info.tagName;
  classWidget.propertyInvalid = _objectSpread({}, classWidget.propertyInvalid);
  if (info.convert) classWidget.mapConvert = _objectSpread(_objectSpread({}, classWidget.mapConvert), info.convert);
  if (info.events) classWidget.events = info.events;
  if (info.hasChildren) classWidget.prototype.render = classWidget.prototype.withChildRender;
  if (info.defaultValue) classWidget.defaultValues = info.defaultValue;
  if (info.require) {
    classWidget.requireProperty = _objectSpread({}, classWidget.requireProperty);
    var _iterator = _createForOfIteratorHelper(info.require),
      _step;
    try {
      for (_iterator.s(); !(_step = _iterator.n()).done;) {
        var key = _step.value;
        classWidget.requireProperty[key] = classWidget.defaultValues[key];
        classWidget.propertyInvalid[key] = true;
      }
    } catch (err) {
      _iterator.e(err);
    } finally {
      _iterator.f();
    }
  }
  for (var property in classWidget.mapConvert) {
    classWidget.propertyInvalid[property] = true;
  }
  for (var _property2 in classWidget.events) {
    classWidget.propertyInvalid[_property2] = 4;
  }
  return classWidget;
}

/***/ }),

/***/ "./ui-src/components/QButton.tsx":
/*!***************************************!*\
  !*** ./ui-src/components/QButton.tsx ***!
  \***************************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "QButton": () => (/* binding */ QButton)
/* harmony export */ });
/* harmony import */ var _BaseWidget__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseWidget */ "./ui-src/components/BaseWidget.tsx");

var QButton = (0,_BaseWidget__WEBPACK_IMPORTED_MODULE_0__.makeWidgetComponent)({
  tagName: 'qtbutton',
  convert: {
    children: 'text'
  },
  events: {
    onClick: function onClick(el) {
      return el.widget.clicked;
    }
  },
  defaultValue: {
    children: ''
  }
});

/***/ }),

/***/ "./ui-src/components/QWidget.tsx":
/*!***************************************!*\
  !*** ./ui-src/components/QWidget.tsx ***!
  \***************************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "QWidget": () => (/* binding */ QWidget)
/* harmony export */ });
/* harmony import */ var _BaseWidget__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseWidget */ "./ui-src/components/BaseWidget.tsx");

var QWidget = (0,_BaseWidget__WEBPACK_IMPORTED_MODULE_0__.makeWidgetComponent)({
  tagName: 'qtwidget',
  hasChildren: true,
  require: ['layout'],
  defaultValue: {
    layout: ''
  }
});

/***/ }),

/***/ "./ui-src/main.tsx":
/*!*************************!*\
  !*** ./ui-src/main.tsx ***!
  \*************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "application": () => (/* binding */ application),
/* harmony export */   "defaultWindow": () => (/* binding */ defaultWindow),
/* harmony export */   "renderApplication": () => (/* binding */ renderApplication),
/* harmony export */   "showSignalConnect": () => (/* binding */ showSignalConnect)
/* harmony export */ });
/* harmony import */ var _App__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./App */ "./ui-src/App.tsx");
/* harmony import */ var _styles_style_scss__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ./styles/style.scss */ "./ui-src/styles/style.scss");


var defaultWindow = window.defaultWindow;
var renderApplication = window.renderApplication;
defaultWindow.x = 0;
defaultWindow.y = 0;
defaultWindow.height = 500;
defaultWindow.title = 'this is window';
defaultWindow.show = true;
defaultWindow.layout = "row";
// defaultWindow.windowFlags = Qt.WindowFlags.Window | Qt.WindowFlags.FramelessWindowHint | Qt.WindowFlags.CustomizeWindowHint
defaultWindow.className = 'main-window';

// const widget = defaultWindow.createElement('qtwidget')
// widget.layout = 'row'
// defaultWindow.appendChild(widget)
// widget.show = true
// widget.className = 'console-view'

// const button = widget.createElement('qtbutton')
// button.text = 'this is button'
// widget.appendChild(button) 

// defaultWindow.reset()

var application = renderApplication(defaultWindow, /*#__PURE__*/React.createElement(_App__WEBPACK_IMPORTED_MODULE_0__.App, null));
function showSignalConnect(obj) {
  for (var key in obj) {
    var val = obj[key];
    if (typeof val !== 'function') continue;
    if (!val.connect && typeof val.connect !== 'function') continue;
    if (!val.disconnect && typeof val.disconnect !== 'function') continue;
    try {
      val.connect(test);
      val.disconnect(test);
      console.log(key);
    } catch (error) {}
  }
  function test() {}
}

/***/ }),

/***/ "./ui-src/styles/style.scss":
/*!**********************************!*\
  !*** ./ui-src/styles/style.scss ***!
  \**********************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

__webpack_require__.r(__webpack_exports__);
// extracted by mini-css-extract-plugin


/***/ }),

/***/ "react":
/*!************************!*\
  !*** external "React" ***!
  \************************/
/***/ ((module) => {

module.exports = React;

/***/ })

/******/ 	});
/************************************************************************/
/******/ 	// The module cache
/******/ 	var __webpack_module_cache__ = {};
/******/ 	
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/ 		// Check if module is in cache
/******/ 		var cachedModule = __webpack_module_cache__[moduleId];
/******/ 		if (cachedModule !== undefined) {
/******/ 			return cachedModule.exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = __webpack_module_cache__[moduleId] = {
/******/ 			// no module.id needed
/******/ 			// no module.loaded needed
/******/ 			exports: {}
/******/ 		};
/******/ 	
/******/ 		// Execute the module function
/******/ 		__webpack_modules__[moduleId](module, module.exports, __webpack_require__);
/******/ 	
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/ 	
/************************************************************************/
/******/ 	/* webpack/runtime/compat get default export */
/******/ 	(() => {
/******/ 		// getDefaultExport function for compatibility with non-harmony modules
/******/ 		__webpack_require__.n = (module) => {
/******/ 			var getter = module && module.__esModule ?
/******/ 				() => (module['default']) :
/******/ 				() => (module);
/******/ 			__webpack_require__.d(getter, { a: getter });
/******/ 			return getter;
/******/ 		};
/******/ 	})();
/******/ 	
/******/ 	/* webpack/runtime/define property getters */
/******/ 	(() => {
/******/ 		// define getter functions for harmony exports
/******/ 		__webpack_require__.d = (exports, definition) => {
/******/ 			for(var key in definition) {
/******/ 				if(__webpack_require__.o(definition, key) && !__webpack_require__.o(exports, key)) {
/******/ 					Object.defineProperty(exports, key, { enumerable: true, get: definition[key] });
/******/ 				}
/******/ 			}
/******/ 		};
/******/ 	})();
/******/ 	
/******/ 	/* webpack/runtime/hasOwnProperty shorthand */
/******/ 	(() => {
/******/ 		__webpack_require__.o = (obj, prop) => (Object.prototype.hasOwnProperty.call(obj, prop))
/******/ 	})();
/******/ 	
/******/ 	/* webpack/runtime/make namespace object */
/******/ 	(() => {
/******/ 		// define __esModule on exports
/******/ 		__webpack_require__.r = (exports) => {
/******/ 			if(typeof Symbol !== 'undefined' && Symbol.toStringTag) {
/******/ 				Object.defineProperty(exports, Symbol.toStringTag, { value: 'Module' });
/******/ 			}
/******/ 			Object.defineProperty(exports, '__esModule', { value: true });
/******/ 		};
/******/ 	})();
/******/ 	
/************************************************************************/
/******/ 	
/******/ 	// startup
/******/ 	// Load entry module and return exports
/******/ 	// This entry module is referenced by other modules so it can't be inlined
/******/ 	var __webpack_exports__ = __webpack_require__("./ui-src/main.tsx");
/******/ 	
/******/ })()
;
//# sourceMappingURL=data:application/json;charset=utf-8;base64,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LENBQUNFLE9BQU8sQ0FBQzhCLElBQUksQ0FBQztNQUNqQmhDLEdBQUcsQ0FBQ0ssVUFBVSxDQUFDMkIsSUFBSSxDQUFDO01BQ3BCekQsT0FBTyxDQUFDQyxHQUFHLENBQUN1QixHQUFHLENBQUM7SUFDakIsQ0FBQyxDQUFDLE9BQU96QixLQUFLLEVBQUUsQ0FFaEI7RUFDRDtFQUNBLFNBQVMwRCxJQUFJLEdBQUUsQ0FBQztBQUNqQjs7Ozs7Ozs7Ozs7QUM3Q0E7Ozs7Ozs7Ozs7O0FDQUE7Ozs7OztVQ0FBO1VBQ0E7O1VBRUE7VUFDQTtVQUNBO1VBQ0E7VUFDQTtVQUNBO1VBQ0E7VUFDQTtVQUNBO1VBQ0E7VUFDQTtVQUNBO1VBQ0E7O1VBRUE7VUFDQTs7VUFFQTtVQUNBO1VBQ0E7Ozs7O1dDdEJBO1dBQ0E7V0FDQTtXQUNBO1dBQ0E7V0FDQSxpQ0FBaUMsV0FBVztXQUM1QztXQUNBOzs7OztXQ1BBO1dBQ0E7V0FDQTtXQUNBO1dBQ0EseUNBQXlDLHdDQUF3QztXQUNqRjtXQUNBO1dBQ0E7Ozs7O1dDUEE7Ozs7O1dDQUE7V0FDQTtXQUNBO1dBQ0EsdURBQXVELGlCQUFpQjtXQUN4RTtXQUNBLGdEQUFnRCxhQUFhO1dBQzdEOzs7OztVRU5BO1VBQ0E7VUFDQTtVQUNBIiwic291cmNlcyI6WyJ3ZWJwYWNrOi8vcXQtcmVhY3QvLi91aS1zcmMvQXBwLnRzeCIsIndlYnBhY2s6Ly9xdC1yZWFjdC8uL3VpLXNyYy9jb21wb25lbnRzL0Jhc2VXaWRnZXQudHN4Iiwid2VicGFjazovL3F0LXJlYWN0Ly4vdWktc3JjL2NvbXBvbmVudHMvUUJ1dHRvbi50c3giLCJ3ZWJwYWNrOi8vcXQtcmVhY3QvLi91aS1zcmMvY29tcG9uZW50cy9RV2lkZ2V0LnRzeCIsIndlYnBhY2s6Ly9xdC1yZWFjdC8uL3VpLXNyYy9tYWluLnRzeCIsIndlYnBhY2s6Ly9xdC1yZWFjdC8uL3VpLXNyYy9zdHlsZXMvc3R5bGUuc2NzcyIsIndlYnBhY2s6Ly9xdC1yZWFjdC9leHRlcm5hbCB2YXIgXCJSZWFjdFwiIiwid2VicGFjazovL3F0LXJlYWN0L3dlYnBhY2svYm9vdHN0cmFwIiwid2VicGFjazovL3F0LXJlYWN0L3dlYnBhY2svcnVudGltZS9jb21wYXQgZ2V0IGRlZmF1bHQgZXhwb3J0Iiwid2VicGFjazovL3F0LXJlYWN0L3dlYnBhY2svcnVudGltZS9kZWZpbmUgcHJvcGVydHkgZ2V0dGVycyIsIndlYnBhY2s6Ly9xdC1yZWFjdC93ZWJwYWNrL3J1bnRpbWUvaGFzT3duUHJvcGVydHkgc2hvcnRoYW5kIiwid2VicGFjazovL3F0LXJlYWN0L3dlYnBhY2svcnVudGltZS9tYWtlIG5hbWVzcGFjZSBvYmplY3QiLCJ3ZWJwYWNrOi8vcXQtcmVhY3Qvd2VicGFjay9iZWZvcmUtc3RhcnR1cCIsIndlYnBhY2s6Ly9xdC1yZWFjdC93ZWJwYWNrL3N0YXJ0dXAiLCJ3ZWJwYWNrOi8vcXQtcmVhY3Qvd2VicGFjay9hZnRlci1zdGFydHVwIl0sInNvdXJjZXNDb250ZW50IjpbImltcG9ydCB7IHVzZVN0YXRlIH0gZnJvbSBcInJlYWN0XCJcclxuaW1wb3J0IHsgUUJ1dHRvbiB9IGZyb20gXCIuL2NvbXBvbmVudHMvUUJ1dHRvblwiXHJcbmltcG9ydCB7IFFXaWRnZXQgfSBmcm9tIFwiLi9jb21wb25lbnRzL1FXaWRnZXRcIlxyXG5pbXBvcnQgeyBkZWZhdWx0V2luZG93IH0gZnJvbSBcIi4vbWFpblwiXHJcblxyXG5leHBvcnQgbGV0IGNoYW5nZVRpdGxlID0gZnVuY3Rpb24gKHRpdGxlKSB7XHJcblx0ZGVmYXVsdFdpbmRvdy50aXRsZSA9IHRpdGxlXHJcbn1cclxuY29uc3QgdW5pdCA9IDcwXHJcbmV4cG9ydCBmdW5jdGlvbiBBcHAoKSB7XHJcblx0Y29uc3QgW2NvdW50LCBzZXRDb3VudF0gPSB1c2VTdGF0ZSg4KVxyXG5cdGZ1bmN0aW9uIG9uQ2xpY2soKSB7XHJcblx0XHRzZXRDb3VudChjb3VudCArIDEpXHJcblx0fVxyXG5cdHJldHVybiA8PlxyXG5cdFx0PFFXaWRnZXQgbGF5b3V0PVwicm93XCI+XHJcblx0XHRcdHt0cnVlICYmIDxRQnV0dG9uPntgdmFsdWU6ICR7Y291bnR9ID0+ICR7Y291bnQgKiB1bml0fWB9PC9RQnV0dG9uPn1cclxuXHRcdFx0PFFCdXR0b24gb25DbGljaz17KCkgPT4ge1xyXG5cdFx0XHRcdHNldENvdW50KGNvdW50ICsgMSlcclxuXHRcdFx0fX0+aW5jcmVhc2U8L1FCdXR0b24+XHJcblx0XHRcdDxRQnV0dG9uIG9uQ2xpY2s9eygpID0+IHtcclxuXHRcdFx0XHRzZXRDb3VudChjb3VudCAtIDEpXHJcblx0XHRcdH19PmRlY3JlYXNlPC9RQnV0dG9uPlxyXG5cdFx0XHQ8UUJ1dHRvbiBvbkNsaWNrPXsoKSA9PiB7XHJcblx0XHRcdFx0YXUzLmV4ZWN1dGUoJ2NsaWNrJywgY291bnQgKiB1bml0KVxyXG5cdFx0XHR9fT5kdW1wPC9RQnV0dG9uPlxyXG5cdFx0XHR7Y291bnQgJSAyICYmIDxRQnV0dG9uPnVjYzwvUUJ1dHRvbj59XHJcblx0XHRcdDxRQnV0dG9uPmRjPC9RQnV0dG9uPlxyXG5cdFx0XHQ8UVdpZGdldCAvPlxyXG5cdFx0PC9RV2lkZ2V0PlxyXG5cdDwvPlxyXG59XHJcblxyXG50cnkge1xyXG5cclxufSBjYXRjaCAoZXJyb3IpIHtcclxuXHRjb25zb2xlLmxvZygnZXJyb3InKVxyXG59IiwiaW1wb3J0IFJlYWN0IGZyb20gXCJyZWFjdFwiXHJcbmltcG9ydCB7IENTU1Byb3BlcnRpZXMgfSBmcm9tIFwicmVhY3RcIlxyXG5cclxuY2xhc3MgQmFzZVdpZGdldDxQID0ge30sIFQgPSBXaWRnZXRQcm9wICYgUD4gZXh0ZW5kcyBSZWFjdC5Db21wb25lbnQ8VD57XHJcblx0Wydjb25zdHJ1Y3RvciddOiB0eXBlb2YgQmFzZVdpZGdldFxyXG5cdHN0YXRpYyB0YWdOYW1lID0gXCJcIlxyXG5cdHN0YXRpYyBwcm9wZXJ0eUludmFsaWQ6IGFueSA9IHtcclxuXHRcdGNoaWxkcmVuOiB0cnVlLFxyXG5cdH1cclxuXHRzdGF0aWMgcmVxdWlyZVByb3BlcnR5ID0ge30gYXMgYW55XHJcblx0c3RhdGljIGV2ZW50cyA9IHt9IGFzIGFueVxyXG5cdHN0YXRpYyBtYXBDb252ZXJ0ID0ge30gYXMgYW55XHJcblx0c3RhdGljIGRlZmF1bHRWYWx1ZXMgPSB7fSBhcyBhbnlcclxuXHJcblx0cmVmID0gUmVhY3QuY3JlYXRlUmVmPGFueT4oKVxyXG5cdGhpc3RvcnlTZXRFdnQgPSB7fSBhcyBhbnlcclxuXHJcblx0Y29tcG9uZW50RGlkTW91bnQoKTogdm9pZCB7XHJcblx0XHRjb25zdCBwcm9wczogYW55ID0gdGhpcy5wcm9wc1xyXG5cdFx0dGhpcy5zZXRQcm9wcyhwcm9wcylcclxuXHRcdGlmIChwcm9wcy5oYXNPd25Qcm9wZXJ0eSgnc2hvdycpKSB7XHJcblx0XHRcdHRoaXMucmVmLmN1cnJlbnQuc2hvdyA9IHByb3BzLnNob3dcclxuXHRcdH0gZWxzZSB7XHJcblx0XHRcdHRoaXMucmVmLmN1cnJlbnQuc2hvdyA9IHRydWVcclxuXHRcdH1cclxuXHR9XHJcblx0Y29tcG9uZW50RGlkVXBkYXRlKHByZXZQcm9wczogUmVhZG9ubHk8VD4pOiB2b2lkIHtcclxuXHRcdHRoaXMuc2V0UHJvcHModGhpcy5wcm9wcywgcHJldlByb3BzKVxyXG5cdH1cclxuXHRzZXRQcm9wcyhuZXdQcm9wczogYW55LCBvbGRQcm9wcyA9ICh7fSBhcyBhbnkpKSB7XHJcblx0XHRjb25zdCBlbCA9IHRoaXMucmVmLmN1cnJlbnRcclxuXHRcdGNvbnN0IHsgcmVxdWlyZVByb3BlcnR5LCBwcm9wZXJ0eUludmFsaWQsIGV2ZW50cywgbWFwQ29udmVydCwgZGVmYXVsdFZhbHVlcyB9ID0gKHRoaXMuY29uc3RydWN0b3IgYXMgdHlwZW9mIEJhc2VXaWRnZXQpXHJcblx0XHRjb25zdCBuZXdIaXN0b3J5U2V0RXZ0ID0ge31cclxuXHRcdC8vIHNldCByZXF1aXJlIHByb3BlcnRpZXNcclxuXHRcdGZvciAoY29uc3QgcHJvcGVydHkgaW4gcmVxdWlyZVByb3BlcnR5KSB7XHJcblx0XHRcdGxldCBuZXdWYWxcclxuXHRcdFx0aWYgKG5ld1Byb3BzLmhhc093blByb3BlcnR5KHByb3BlcnR5KSkge1xyXG5cdFx0XHRcdG5ld1ZhbCA9IG5ld1Byb3BzW3Byb3BlcnR5XSB8fCBkZWZhdWx0VmFsdWVzW3Byb3BlcnR5XVxyXG5cdFx0XHR9IGVsc2Uge1xyXG5cdFx0XHRcdG5ld1ZhbCA9IHJlcXVpcmVQcm9wZXJ0eVtwcm9wZXJ0eV1cclxuXHRcdFx0fVxyXG5cdFx0XHRpZiAoZWxbcHJvcGVydHldID09PSBuZXdWYWwpIGNvbnRpbnVlXHJcblx0XHRcdGVsW3Byb3BlcnR5XSA9IG5ld1ZhbFxyXG5cdFx0fVxyXG5cdFx0Ly8gY29udmVydCBwcm9wc1xyXG5cdFx0Zm9yIChjb25zdCBrZXkgaW4gbWFwQ29udmVydCkge1xyXG5cdFx0XHRjb25zdCB2YWwgPSBuZXdQcm9wc1trZXldIHx8IGRlZmF1bHRWYWx1ZXNba2V5XVxyXG5cdFx0XHRjb25zdCBlbFByb3BlcnR5ID0gbWFwQ29udmVydFtrZXldXHJcblx0XHRcdGlmIChlbFtlbFByb3BlcnR5XSA9PT0gdmFsKSBjb250aW51ZVxyXG5cdFx0XHRlbFtlbFByb3BlcnR5XSA9IHZhbFxyXG5cdFx0fVxyXG5cdFx0Ly8gc2V0IHByb3BlcnRpZXNcclxuXHRcdGZvciAoY29uc3QgcHJvcGVydHkgaW4gbmV3UHJvcHMpIHtcclxuXHRcdFx0Y29uc3QgdmFsID0gbmV3UHJvcHNbcHJvcGVydHldXHJcblx0XHRcdGlmIChwcm9wZXJ0eUludmFsaWRbcHJvcGVydHldKSB7XHJcblx0XHRcdFx0aWYgKHByb3BlcnR5SW52YWxpZFtwcm9wZXJ0eV0gPT09IDQpIHtcclxuXHRcdFx0XHRcdGNvbnN0IGNvbm5lY3QgPSBldmVudHNbcHJvcGVydHldKGVsKVxyXG5cdFx0XHRcdFx0aWYgKHR5cGVvZiBjb25uZWN0ICE9PSAnZnVuY3Rpb24nKSBjb250aW51ZVxyXG5cdFx0XHRcdFx0aWYgKHRoaXMuaGlzdG9yeVNldEV2dFtwcm9wZXJ0eV0pIHtcclxuXHRcdFx0XHRcdFx0Y29uc3Qgb2xkRnVuYyA9IG9sZFByb3BzW3Byb3BlcnR5XVxyXG5cdFx0XHRcdFx0XHRpZiAodHlwZW9mIHZhbCA9PT0gJ2Z1bmN0aW9uJykge1xyXG5cdFx0XHRcdFx0XHRcdGlmIChvbGRGdW5jICE9PSB2YWwpIHtcclxuXHRcdFx0XHRcdFx0XHRcdGNvbm5lY3QuZGlzY29ubmVjdChvbGRGdW5jKVxyXG5cdFx0XHRcdFx0XHRcdFx0Y29ubmVjdC5jb25uZWN0KHZhbClcclxuXHRcdFx0XHRcdFx0XHR9XHJcblx0XHRcdFx0XHRcdFx0bmV3SGlzdG9yeVNldEV2dFtwcm9wZXJ0eV0gPSB0cnVlXHJcblx0XHRcdFx0XHRcdH0gZWxzZSB7XHJcblx0XHRcdFx0XHRcdFx0Y29ubmVjdC5kaXNjb25uZWN0KG9sZEZ1bmMpXHJcblx0XHRcdFx0XHRcdH1cclxuXHRcdFx0XHRcdH0gZWxzZSB7XHJcblx0XHRcdFx0XHRcdGlmICh0eXBlb2YgdmFsICE9PSAnZnVuY3Rpb24nKSBjb250aW51ZVxyXG5cdFx0XHRcdFx0XHRjb25uZWN0LmNvbm5lY3QodmFsKVxyXG5cdFx0XHRcdFx0XHRuZXdIaXN0b3J5U2V0RXZ0W3Byb3BlcnR5XSA9IHRydWVcclxuXHRcdFx0XHRcdH1cclxuXHRcdFx0XHR9XHJcblx0XHRcdFx0Y29udGludWVcclxuXHRcdFx0fVxyXG5cdFx0XHRpZiAoZWxbcHJvcGVydHldID09PSB2YWwpIGNvbnRpbnVlXHJcblx0XHRcdGVsW3Byb3BlcnR5XSA9IHZhbFxyXG5cdFx0fVxyXG5cclxuXHRcdHRoaXMuaGlzdG9yeVNldEV2dCA9IG5ld0hpc3RvcnlTZXRFdnRcclxuXHR9XHJcblx0d2l0aENoaWxkUmVuZGVyKCkge1xyXG5cdFx0cmV0dXJuIFJlYWN0LmNyZWF0ZUVsZW1lbnQodGhpcy5jb25zdHJ1Y3Rvci50YWdOYW1lLCB7IHJlZjogdGhpcy5yZWYsIGNoaWxkcmVuOiAodGhpcy5wcm9wcyBhcyBhbnkpLmNoaWxkcmVuIH0pXHJcblx0fVxyXG5cdHJlbmRlcigpIHtcclxuXHRcdHJldHVybiBSZWFjdC5jcmVhdGVFbGVtZW50KHRoaXMuY29uc3RydWN0b3IudGFnTmFtZSwgeyByZWY6IHRoaXMucmVmIH0pXHJcblx0fVxyXG59XHJcblxyXG5leHBvcnQgZnVuY3Rpb24gbWFrZVdpZGdldENvbXBvbmVudDxUID0ge30+KGluZm86IFBhcmFtV2lkZ2V0Q29tcG9uZW50PFQ+KSB7XHJcblx0Y29uc3QgY2xhc3NXaWRnZXQgPSBjbGFzcyBleHRlbmRzIEJhc2VXaWRnZXQ8VD57IH1cclxuXHRjbGFzc1dpZGdldC50YWdOYW1lID0gaW5mby50YWdOYW1lXHJcblx0Y2xhc3NXaWRnZXQucHJvcGVydHlJbnZhbGlkID0geyAuLi5jbGFzc1dpZGdldC5wcm9wZXJ0eUludmFsaWQgfVxyXG5cclxuXHRpZiAoaW5mby5jb252ZXJ0KSBjbGFzc1dpZGdldC5tYXBDb252ZXJ0ID0geyAuLi5jbGFzc1dpZGdldC5tYXBDb252ZXJ0LCAuLi5pbmZvLmNvbnZlcnQgfVxyXG5cdGlmIChpbmZvLmV2ZW50cykgY2xhc3NXaWRnZXQuZXZlbnRzID0gaW5mby5ldmVudHNcclxuXHRpZiAoaW5mby5oYXNDaGlsZHJlbikgY2xhc3NXaWRnZXQucHJvdG90eXBlLnJlbmRlciA9IGNsYXNzV2lkZ2V0LnByb3RvdHlwZS53aXRoQ2hpbGRSZW5kZXJcclxuXHRpZiAoaW5mby5kZWZhdWx0VmFsdWUpIGNsYXNzV2lkZ2V0LmRlZmF1bHRWYWx1ZXMgPSBpbmZvLmRlZmF1bHRWYWx1ZVxyXG5cdGlmIChpbmZvLnJlcXVpcmUpIHtcclxuXHRcdGNsYXNzV2lkZ2V0LnJlcXVpcmVQcm9wZXJ0eSA9IHsgLi4uY2xhc3NXaWRnZXQucmVxdWlyZVByb3BlcnR5IH1cclxuXHRcdGZvciAoY29uc3Qga2V5IG9mIGluZm8ucmVxdWlyZSkge1xyXG5cdFx0XHRjbGFzc1dpZGdldC5yZXF1aXJlUHJvcGVydHlba2V5XSA9IGNsYXNzV2lkZ2V0LmRlZmF1bHRWYWx1ZXNba2V5XVxyXG5cdFx0XHRjbGFzc1dpZGdldC5wcm9wZXJ0eUludmFsaWRba2V5XSA9IHRydWVcclxuXHRcdH1cclxuXHR9XHJcblxyXG5cdGZvciAoY29uc3QgcHJvcGVydHkgaW4gY2xhc3NXaWRnZXQubWFwQ29udmVydCkge1xyXG5cdFx0Y2xhc3NXaWRnZXQucHJvcGVydHlJbnZhbGlkW3Byb3BlcnR5XSA9IHRydWVcclxuXHR9XHJcblx0Zm9yIChjb25zdCBwcm9wZXJ0eSBpbiBjbGFzc1dpZGdldC5ldmVudHMpIHtcclxuXHRcdGNsYXNzV2lkZ2V0LnByb3BlcnR5SW52YWxpZFtwcm9wZXJ0eV0gPSA0XHJcblx0fVxyXG5cdHJldHVybiBjbGFzc1dpZGdldFxyXG59XHJcblxyXG50eXBlIFdpZGdldFByb3AgPSB7XHJcblx0eD86IG51bWJlclxyXG5cdHk/OiBudW1iZXJcclxuXHR3aWR0aD86IG51bWJlclxyXG5cdGhlaWdodD86IG51bWJlclxyXG5cdHRpdGxlPzogc3RyaW5nXHJcblx0c2hvdz86IGJvb2xlYW5cclxuXHRkaXNhYmxlZD86IGJvb2xlYW5cclxuXHRjbGFzc05hbWU/OiBzdHJpbmdcclxuXHRzdHlsZT86IENTU1Byb3BlcnRpZXNcclxuXHR2ZXJQb2xpY3k/OiBRU2l6ZVBvbGljeS5Qb2xpY3lcclxuXHRob3JQb2xpY3k/OiBRU2l6ZVBvbGljeS5Qb2xpY3lcclxuXHRncmlkQ29sc3Bhbj86IG51bWJlclxyXG5cdGdyaWRSb3dzcGFuPzogbnVtYmVyXHJcbn1cclxudHlwZSBQYXJhbVdpZGdldENvbXBvbmVudDxQLCBUID0gV2lkZ2V0UHJvcCAmIFAsIEtFWVMgPSBrZXlvZiBUPiA9IHtcclxuXHR0YWdOYW1lOiBzdHJpbmdcclxuXHRyZXF1aXJlPzogS0VZU1tdXHJcblx0Y29udmVydD86IHsgW24gaW4ga2V5b2YgVF06IHN0cmluZyB9XHJcblx0aGFzQ2hpbGRyZW4/OiBib29sZWFuXHJcblx0ZGVmYXVsdFZhbHVlPzogeyBbbiBpbiBrZXlvZiBUXTogYW55IH1cclxuXHRldmVudHM/OiB7IFtuIGluIGtleW9mIFRdOiAoX3RoaXNQYXJhbTogYW55KSA9PiBhbnkgfVxyXG59IiwiaW1wb3J0IHsgbWFrZVdpZGdldENvbXBvbmVudCB9IGZyb20gXCIuL0Jhc2VXaWRnZXRcIlxyXG5cclxuZXhwb3J0IGNvbnN0IFFCdXR0b24gPSBtYWtlV2lkZ2V0Q29tcG9uZW50PFFCdXR0b25Qcm9wcz4oe1xyXG5cdHRhZ05hbWU6ICdxdGJ1dHRvbicsXHJcblx0Y29udmVydDoge1xyXG5cdFx0Y2hpbGRyZW46ICd0ZXh0J1xyXG5cdH0sXHJcblx0ZXZlbnRzOiB7XHJcblx0XHRvbkNsaWNrOiAoZWwpID0+IGVsLndpZGdldC5jbGlja2VkXHJcblx0fSxcclxuXHRkZWZhdWx0VmFsdWU6IHtcclxuXHRcdGNoaWxkcmVuOiAnJ1xyXG5cdH1cclxufSlcclxudHlwZSBRQnV0dG9uUHJvcHMgPSB7XHJcblx0b25DbGljaz86ICgpID0+IHZvaWRcclxuXHRjaGlsZHJlbj86IHN0cmluZ1xyXG59IiwiaW1wb3J0IHsgbWFrZVdpZGdldENvbXBvbmVudCB9IGZyb20gXCIuL0Jhc2VXaWRnZXRcIlxyXG5cclxuZXhwb3J0IGNvbnN0IFFXaWRnZXQgPSBtYWtlV2lkZ2V0Q29tcG9uZW50PFFXaWRnZXRQcm9wcz4oe1xyXG5cdHRhZ05hbWU6ICdxdHdpZGdldCcsXHJcblx0aGFzQ2hpbGRyZW46IHRydWUsXHJcblx0cmVxdWlyZTogWydsYXlvdXQnXSxcclxuXHRkZWZhdWx0VmFsdWU6IHtcclxuXHRcdGxheW91dDogJydcclxuXHR9XHJcbn0pXHJcblxyXG50eXBlIFFXaWRnZXRQcm9wcyA9IHtcclxuXHRjaGlsZHJlbj86IGFueVxyXG5cdGxheW91dD86ICcnIHwgJ3JvdycgfCAnY29sdW1uJ1xyXG59XHJcbiIsImltcG9ydCB7IENTU1Byb3BlcnRpZXMgfSBmcm9tIFwicmVhY3RcIjtcclxuaW1wb3J0IHsgQXBwIH0gZnJvbSBcIi4vQXBwXCI7XHJcbmltcG9ydCBcIi4vc3R5bGVzL3N0eWxlLnNjc3NcIlxyXG5cclxuZXhwb3J0IGNvbnN0IGRlZmF1bHRXaW5kb3cgPSAod2luZG93IGFzIGFueSkuZGVmYXVsdFdpbmRvdztcclxuZXhwb3J0IGNvbnN0IHJlbmRlckFwcGxpY2F0aW9uID0gKHdpbmRvdyBhcyBhbnkpLnJlbmRlckFwcGxpY2F0aW9uXHJcblxyXG5kZWZhdWx0V2luZG93LnggPTBcclxuZGVmYXVsdFdpbmRvdy55ID0gMFxyXG5kZWZhdWx0V2luZG93LmhlaWdodCA9IDUwMFxyXG5kZWZhdWx0V2luZG93LnRpdGxlID0gJ3RoaXMgaXMgd2luZG93J1xyXG5kZWZhdWx0V2luZG93LnNob3cgPSB0cnVlXHJcbmRlZmF1bHRXaW5kb3cubGF5b3V0ID0gXCJyb3dcIlxyXG4vLyBkZWZhdWx0V2luZG93LndpbmRvd0ZsYWdzID0gUXQuV2luZG93RmxhZ3MuV2luZG93IHwgUXQuV2luZG93RmxhZ3MuRnJhbWVsZXNzV2luZG93SGludCB8IFF0LldpbmRvd0ZsYWdzLkN1c3RvbWl6ZVdpbmRvd0hpbnRcclxuZGVmYXVsdFdpbmRvdy5jbGFzc05hbWUgPSAnbWFpbi13aW5kb3cnXHJcblxyXG4vLyBjb25zdCB3aWRnZXQgPSBkZWZhdWx0V2luZG93LmNyZWF0ZUVsZW1lbnQoJ3F0d2lkZ2V0JylcclxuLy8gd2lkZ2V0LmxheW91dCA9ICdyb3cnXHJcbi8vIGRlZmF1bHRXaW5kb3cuYXBwZW5kQ2hpbGQod2lkZ2V0KVxyXG4vLyB3aWRnZXQuc2hvdyA9IHRydWVcclxuLy8gd2lkZ2V0LmNsYXNzTmFtZSA9ICdjb25zb2xlLXZpZXcnXHJcblxyXG4vLyBjb25zdCBidXR0b24gPSB3aWRnZXQuY3JlYXRlRWxlbWVudCgncXRidXR0b24nKVxyXG4vLyBidXR0b24udGV4dCA9ICd0aGlzIGlzIGJ1dHRvbidcclxuLy8gd2lkZ2V0LmFwcGVuZENoaWxkKGJ1dHRvbikgXHJcblxyXG4vLyBkZWZhdWx0V2luZG93LnJlc2V0KClcclxuXHJcbmV4cG9ydCBjb25zdCBhcHBsaWNhdGlvbiA9IHJlbmRlckFwcGxpY2F0aW9uKGRlZmF1bHRXaW5kb3csIDxBcHAvPilcclxuXHJcbmV4cG9ydCBmdW5jdGlvbiBzaG93U2lnbmFsQ29ubmVjdChvYmope1xyXG5cdGZvcihjb25zdCBrZXkgaW4gb2JqKXtcclxuXHRcdGNvbnN0IHZhbCA9IG9ialtrZXldXHJcblx0XHRpZih0eXBlb2YgdmFsICE9PSAnZnVuY3Rpb24nKSBjb250aW51ZVxyXG5cdFx0aWYoIXZhbC5jb25uZWN0ICYmIHR5cGVvZiB2YWwuY29ubmVjdCAhPT0gJ2Z1bmN0aW9uJykgY29udGludWVcclxuXHRcdGlmKCF2YWwuZGlzY29ubmVjdCAmJiB0eXBlb2YgdmFsLmRpc2Nvbm5lY3QgIT09ICdmdW5jdGlvbicpIGNvbnRpbnVlXHJcblx0XHR0cnkge1xyXG5cdFx0XHR2YWwuY29ubmVjdCh0ZXN0KVxyXG5cdFx0XHR2YWwuZGlzY29ubmVjdCh0ZXN0KVxyXG5cdFx0XHRjb25zb2xlLmxvZyhrZXkpXHJcblx0XHR9IGNhdGNoIChlcnJvcikge1xyXG5cdFx0XHRcclxuXHRcdH1cclxuXHR9XHJcblx0ZnVuY3Rpb24gdGVzdCgpe31cclxufVxyXG4iLCIvLyBleHRyYWN0ZWQgYnkgbWluaS1jc3MtZXh0cmFjdC1wbHVnaW5cbmV4cG9ydCB7fTsiLCJtb2R1bGUuZXhwb3J0cyA9IFJlYWN0OyIsIi8vIFRoZSBtb2R1bGUgY2FjaGVcbnZhciBfX3dlYnBhY2tfbW9kdWxlX2NhY2hlX18gPSB7fTtcblxuLy8gVGhlIHJlcXVpcmUgZnVuY3Rpb25cbmZ1bmN0aW9uIF9fd2VicGFja19yZXF1aXJlX18obW9kdWxlSWQpIHtcblx0Ly8gQ2hlY2sgaWYgbW9kdWxlIGlzIGluIGNhY2hlXG5cdHZhciBjYWNoZWRNb2R1bGUgPSBfX3dlYnBhY2tfbW9kdWxlX2NhY2hlX19bbW9kdWxlSWRdO1xuXHRpZiAoY2FjaGVkTW9kdWxlICE9PSB1bmRlZmluZWQpIHtcblx0XHRyZXR1cm4gY2FjaGVkTW9kdWxlLmV4cG9ydHM7XG5cdH1cblx0Ly8gQ3JlYXRlIGEgbmV3IG1vZHVsZSAoYW5kIHB1dCBpdCBpbnRvIHRoZSBjYWNoZSlcblx0dmFyIG1vZHVsZSA9IF9fd2VicGFja19tb2R1bGVfY2FjaGVfX1ttb2R1bGVJZF0gPSB7XG5cdFx0Ly8gbm8gbW9kdWxlLmlkIG5lZWRlZFxuXHRcdC8vIG5vIG1vZHVsZS5sb2FkZWQgbmVlZGVkXG5cdFx0ZXhwb3J0czoge31cblx0fTtcblxuXHQvLyBFeGVjdXRlIHRoZSBtb2R1bGUgZnVuY3Rpb25cblx0X193ZWJwYWNrX21vZHVsZXNfX1ttb2R1bGVJZF0obW9kdWxlLCBtb2R1bGUuZXhwb3J0cywgX193ZWJwYWNrX3JlcXVpcmVfXyk7XG5cblx0Ly8gUmV0dXJuIHRoZSBleHBvcnRzIG9mIHRoZSBtb2R1bGVcblx0cmV0dXJuIG1vZHVsZS5leHBvcnRzO1xufVxuXG4iLCIvLyBnZXREZWZhdWx0RXhwb3J0IGZ1bmN0aW9uIGZvciBjb21wYXRpYmlsaXR5IHdpdGggbm9uLWhhcm1vbnkgbW9kdWxlc1xuX193ZWJwYWNrX3JlcXVpcmVfXy5uID0gKG1vZHVsZSkgPT4ge1xuXHR2YXIgZ2V0dGVyID0gbW9kdWxlICYmIG1vZHVsZS5fX2VzTW9kdWxlID9cblx0XHQoKSA9PiAobW9kdWxlWydkZWZhdWx0J10pIDpcblx0XHQoKSA9PiAobW9kdWxlKTtcblx0X193ZWJwYWNrX3JlcXVpcmVfXy5kKGdldHRlciwgeyBhOiBnZXR0ZXIgfSk7XG5cdHJldHVybiBnZXR0ZXI7XG59OyIsIi8vIGRlZmluZSBnZXR0ZXIgZnVuY3Rpb25zIGZvciBoYXJtb255IGV4cG9ydHNcbl9fd2VicGFja19yZXF1aXJlX18uZCA9IChleHBvcnRzLCBkZWZpbml0aW9uKSA9PiB7XG5cdGZvcih2YXIga2V5IGluIGRlZmluaXRpb24pIHtcblx0XHRpZihfX3dlYnBhY2tfcmVxdWlyZV9fLm8oZGVmaW5pdGlvbiwga2V5KSAmJiAhX193ZWJwYWNrX3JlcXVpcmVfXy5vKGV4cG9ydHMsIGtleSkpIHtcblx0XHRcdE9iamVjdC5kZWZpbmVQcm9wZXJ0eShleHBvcnRzLCBrZXksIHsgZW51bWVyYWJsZTogdHJ1ZSwgZ2V0OiBkZWZpbml0aW9uW2tleV0gfSk7XG5cdFx0fVxuXHR9XG59OyIsIl9fd2VicGFja19yZXF1aXJlX18ubyA9IChvYmosIHByb3ApID0+IChPYmplY3QucHJvdG90eXBlLmhhc093blByb3BlcnR5LmNhbGwob2JqLCBwcm9wKSkiLCIvLyBkZWZpbmUgX19lc01vZHVsZSBvbiBleHBvcnRzXG5fX3dlYnBhY2tfcmVxdWlyZV9fLnIgPSAoZXhwb3J0cykgPT4ge1xuXHRpZih0eXBlb2YgU3ltYm9sICE9PSAndW5kZWZpbmVkJyAmJiBTeW1ib2wudG9TdHJpbmdUYWcpIHtcblx0XHRPYmplY3QuZGVmaW5lUHJvcGVydHkoZXhwb3J0cywgU3ltYm9sLnRvU3RyaW5nVGFnLCB7IHZhbHVlOiAnTW9kdWxlJyB9KTtcblx0fVxuXHRPYmplY3QuZGVmaW5lUHJvcGVydHkoZXhwb3J0cywgJ19fZXNNb2R1bGUnLCB7IHZhbHVlOiB0cnVlIH0pO1xufTsiLCIiLCIvLyBzdGFydHVwXG4vLyBMb2FkIGVudHJ5IG1vZHVsZSBhbmQgcmV0dXJuIGV4cG9ydHNcbi8vIFRoaXMgZW50cnkgbW9kdWxlIGlzIHJlZmVyZW5jZWQgYnkgb3RoZXIgbW9kdWxlcyBzbyBpdCBjYW4ndCBiZSBpbmxpbmVkXG52YXIgX193ZWJwYWNrX2V4cG9ydHNfXyA9IF9fd2VicGFja19yZXF1aXJlX18oXCIuL3VpLXNyYy9tYWluLnRzeFwiKTtcbiIsIiJdLCJuYW1lcyI6WyJ1c2VTdGF0ZSIsIlFCdXR0b24iLCJRV2lkZ2V0IiwiZGVmYXVsdFdpbmRvdyIsImNoYW5nZVRpdGxlIiwidGl0bGUiLCJ1bml0IiwiQXBwIiwiY291bnQiLCJzZXRDb3VudCIsIm9uQ2xpY2siLCJhdTMiLCJleGVjdXRlIiwiZXJyb3IiLCJjb25zb2xlIiwibG9nIiwiUmVhY3QiLCJCYXNlV2lkZ2V0IiwiY3JlYXRlUmVmIiwicHJvcHMiLCJzZXRQcm9wcyIsImhhc093blByb3BlcnR5IiwicmVmIiwiY3VycmVudCIsInNob3ciLCJwcmV2UHJvcHMiLCJuZXdQcm9wcyIsIm9sZFByb3BzIiwiZWwiLCJjb25zdHJ1Y3RvciIsInJlcXVpcmVQcm9wZXJ0eSIsInByb3BlcnR5SW52YWxpZCIsImV2ZW50cyIsIm1hcENvbnZlcnQiLCJkZWZhdWx0VmFsdWVzIiwibmV3SGlzdG9yeVNldEV2dCIsInByb3BlcnR5IiwibmV3VmFsIiwia2V5IiwidmFsIiwiZWxQcm9wZXJ0eSIsImNvbm5lY3QiLCJoaXN0b3J5U2V0RXZ0Iiwib2xkRnVuYyIsImRpc2Nvbm5lY3QiLCJjcmVhdGVFbGVtZW50IiwidGFnTmFtZSIsImNoaWxkcmVuIiwiQ29tcG9uZW50IiwibWFrZVdpZGdldENvbXBvbmVudCIsImluZm8iLCJjbGFzc1dpZGdldCIsImNvbnZlcnQiLCJoYXNDaGlsZHJlbiIsInByb3RvdHlwZSIsInJlbmRlciIsIndpdGhDaGlsZFJlbmRlciIsImRlZmF1bHRWYWx1ZSIsInJlcXVpcmUiLCJ3aWRnZXQiLCJjbGlja2VkIiwibGF5b3V0Iiwid2luZG93IiwicmVuZGVyQXBwbGljYXRpb24iLCJ4IiwieSIsImhlaWdodCIsImNsYXNzTmFtZSIsImFwcGxpY2F0aW9uIiwic2hvd1NpZ25hbENvbm5lY3QiLCJvYmoiLCJ0ZXN0Il0sInNvdXJjZVJvb3QiOiIifQ==