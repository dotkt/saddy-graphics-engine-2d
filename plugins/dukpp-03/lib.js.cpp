#include<string>
extern const std::string __context_eval_info;
const std::string __context_eval_info = std::string("var sad = {};\n"
"sad.internal = {};\n"
"sad.util = {};\n"
"\n"
"sad.Point2D = SadPoint2D;\n"
"sad.Point3D = SadPoint3D;\n"
"sad.Point2I = SadPoint2I;\n"
"sad.Point3I = SadPoint3I;\n"
"\n"
"\n"
"sad.internal.plus = function(a, b) { return a + b; };\n"
"sad.internal.minus = function(a, b) { return a - b; };\n"
"sad.internal.multiply = function(a, b) { return a * b; };\n"
"sad.internal.divide = function(a, b) { return a / b; };\n"
"\n"
"\n"
"sad.internal.copyObject = function(dest, src) {\n"
"	for(var key in src) {\n"
"		if (src.hasOwnProperty(key)) {\n"
"			dest[key] = src[key];\n"
"		}\n"
"	}\n"
"}\n"
"\n"
"sad.internal.makeMathFns = function(obj) {\n"
"	obj.plus = function(o) {\n"
"		return this.makeWithFn(sad.internal.plus, o);\n"
"	};\n"
"\n"
"	obj.minus = function(o) {\n"
"		return this.makeWithFn(sad.internal.minus, o);\n"
"	};\n"
"\n"
"	obj.multiply = function(o) {\n"
"		return this.makeWithFn(sad.internal.multiply, o);\n"
"	};\n"
"\n"
"	obj.divide = function(o) {\n"
"		return this.makeWithFn(sad.internal.divide, o);\n"
"	};\n"
"};\n"
"\n"
"//	sad.Point2D bindings\n"
"\n"
"sad.Point2D.prototype.to3d = function() {\n"
"	return new sad.Point3D(this.x, this.y, 0);\n"
"};\n"
"\n"
"sad.Point2D.prototype.to3i = function() {\n"
"	return new sad.Point3I(this.x, this.y, 0);\n"
"};\n"
"\n"
"sad.Point2D.prototype.to2i = function() {\n"
"	return new sad.Point2I(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point2D.prototype.makeWithFn = function(fn, o) {\n"
"	return new sad.Point2D(fn(this.x, o.x), fn(this.y, o.y));\n"
"};\n"
"\n"
"sad.internal.makeMathFns(sad.Point2D.prototype);\n"
"\n"
"sad.Point2D.prototype.toString = function() {\n"
"	return \"sad::Point2D(\" + this.x + ',' + this.y + ')';\n"
"};\n"
"\n"
"//	sad.Point3D bindings\n"
"\n"
"sad.Point3D.prototype.to2d = function() {\n"
"	return new sad.Point2D(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point3D.prototype.to2i = function() {\n"
"	return new sad.Point2I(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point3D.prototype.to3I = function() {\n"
"	return new sad.Point3I(this.x, this.y, this.z);\n"
"};\n"
"\n"
"\n"
"sad.Point3D.prototype.makeWithFn = function(fn, o) {\n"
"	return new sad.Point3D(fn(this.x, o.x), fn(this.y, o.y), fn(this.z, o.z));\n"
"};\n"
"\n"
"sad.internal.makeMathFns(sad.Point3D.prototype);\n"
"\n"
"sad.Point3D.prototype.toString = function() {\n"
"	return \"sad::Point3D(\" + this.x + ',' + this.y + ',' + this.z + ')';\n"
"};\n"
"\n"
"// sad.Point2I \n"
"\n"
"sad.Point2I.prototype.to2d = function() {\n"
"	return new sad.Point2D(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point2I.prototype.to3d = function() {\n"
"	return new sad.Point3D(this.x, this.y, 0);\n"
"};\n"
"\n"
"sad.Point2I.prototype.to3i = function() {\n"
"	return new sad.Point3I(this.x, this.y, 0);\n"
"};\n"
"\n"
"\n"
"sad.Point2I.prototype.makeWithFn = function(fn, o) {\n"
"	return new sad.Point2I(fn(this.x, o.x), fn(this.y, o.y));\n"
"};\n"
"\n"
"sad.internal.makeMathFns(sad.Point2I.prototype);\n"
"\n"
"sad.Point2I.prototype.toString = function() {\n"
"	return \"sad::Point2I(\" + this.x + ',' + this.y	+ ')';\n"
"};\n"
"\n"
"// sad.Point3I\n"
"\n"
"sad.Point3I.prototype.to2d = function() {\n"
"	return new sad.Point2D(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point3I.prototype.to2i = function() {\n"
"	return new sad.Point2I(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point3I.prototype.to3d = function() {\n"
"	return new sad.Point3D(this.x, this.y, this.z);\n"
"};\n"
"\n"
"\n"
"sad.Point3I.prototype.makeWithFn = function(fn, o) {\n"
"	return new sad.Point3I(fn(this.x, o.x), fn(this.y, o.y), fn(this.z, o.z));\n"
"};\n"
"\n"
"sad.internal.makeMathFns(sad.Point3I.prototype);\n"
"\n"
"sad.Point3I.prototype.toString = function() {\n"
"	return \"sad::Point3I(\" + this.x + ',' + this.y + ',' + this.z + ')';\n"
"};\n"
"\n"
"// sad.p2d.Vector bindings\n"
"\n"
"sad.p2d = {};\n"
"sad.p2d.Vector = SadP2DVector;\n"
"\n"
"\n"
"sad.p2d.Vector.prototype.to3d = function() {\n"
"	return new sad.Point3D(this.x, this.y, 0);\n"
"};\n"
"\n"
"sad.p2d.Vector.prototype.to3i = function() {\n"
"	return new sad.Point3I(this.x, this.y, 0);\n"
"};\n"
"\n"
"sad.p2d.Vector.prototype.to2i = function() {\n"
"	return new sad.Point2I(this.x, this.y);\n"
"};\n"
"\n"
"sad.p2d.Vector.prototype.makeWithFn = function(fn, o) {\n"
"	return new sad.Point2D(fn(this.x, o.x), fn(this.y, o.y));\n"
"};\n"
"\n"
"sad.internal.makeMathFns(sad.p2d.Vector.prototype);\n"
"\n"
"sad.p2d.Vector.prototype.toString = function() {\n"
"	return \"sad::p2d::Vector(\" + this.x + ',' + this.y + ')';\n"
"};\n"
"\n"
"sad.p2d.modulo = SadP2DModulo;\n"
"sad.p2d.basis = SadP2DBasis;\n"
"sad.p2d.unit = SadP2DUnit;\n"
"sad.p2d.scalar = SadP2DScalar;\n"
"sad.p2d.ortho = SadP2DOrtho;\n"
"sad.p2d.OVI_DEG_90 = 0;\n"
"sad.p2d.OVI_DEG_270 = 1;\n"
"\n"
"// sad.Size2D\n"
"\n"
"sad.Size2D = SadSize2D;\n"
"sad.Size2D.prototype.to2i = function() {\n"
"	return new sad.Size2I(this.width, this.height);\n"
"};\n"
"sad.Size2D.prototype.toString = function() {\n"
"	return \"sad::Size2D(\" + this.width + ',' + this.height + ')';\n"
"};\n"
"\n"
"// sad.Size2I\n"
"\n"
"sad.Size2I = SadSize2I;\n"
"sad.Size2I.prototype.to2d = function() {\n"
"	return new sad.Size2D(this.width, this.height);\n"
"};\n"
"sad.Size2I.prototype.toString = function() {\n"
"	return \"sad::Size2I(\" + this.width + ',' + this.height + ')';\n"
"};\n"
"\n"
"// sad.Rect2D\n"
"\n"
"sad.Rect2D = SadRect2D;\n"
"\n"
"sad.Rect2D.prototype.to2i = function() {\n"
"	return new sad.Rect2I(this.p0().to2i(), this.p1().to2i(), this.p2().to2i(), this.p3().to2i());\n"
"};\n"
"sad.Rect2D.prototype.toString = function() {\n"
"	var result = [];\n"
"	for(var i = 0; i < 4; i++)\n"
"	{\n"
"		result.push(sad.Point2D.prototype.toString.call(this['p' + i]()));\n"
"	}\n"
"	return \"sad::Rect2D(\" +	 result.join(', ') + ')';\n"
"};\n"
"\n"
"// sad.Rect2I\n"
"\n"
"sad.Rect2I = SadRect2I;\n"
"\n"
"sad.Rect2I.prototype.to2d = function() {\n"
"	return new sad.Rect2D(this.p0().to2d(), this.p1().to2d(), this.p2().to2d(), this.p3().to2d());\n"
"};\n"
"sad.Rect2I.prototype.toString = function() {\n"
"	var result = [];\n"
"	for(var i = 0; i < 4; i++)\n"
"	{\n"
"		result.push(sad.Point2I.prototype.toString.call(this['p' + i]()));\n"
"	}\n"
"	return \"sad::Rect2I(\" +	 result.join(', ') + ')';\n"
"};\n"
"\n"
"// sad.RectPoint3D\n"
"\n"
"sad.RectPoint3D = SadRectPoint3D;\n"
"sad.Rect3D = SadRectPoint3D;\n"
"\n"
"sad.RectPoint3D.prototype.toString = function() {\n"
"	var result = [];\n"
"	for(var i = 0; i < 4; i++)\n"
"	{\n"
"		result.push(sad.Point3D.prototype.toString.call(this['p' + i]()));\n"
"	}\n"
"	return \"sad::Rect<sad::Point3D>(\" +	 result.join(', ') + ')';\n"
"};\n"
"\n"
"// console object\n"
"\n"
"var console = {};\n"
"console.dump = function(o) {\n"
"	var type = typeof o;\n"
"	if (type == \"undefined\") { return \"undefined\"};\n"
"	if ((type == \"boolean\") || (type == \"number\") || (type == \"string\") || (type == \"symbol\") || (type == \"function\")) { return o.toString();}\n"
"	if (type == \"object\")\n"
"	{\n"
"		if (o === null)\n"
"		{\n"
"			return \"null\";\n"
"		}\n"
"		if (o instanceof Array)\n"
"		{\n"
"			var	 i = 0; \n"
"			var	 result = [];\n"
"			for(var i = 0; i < o.length; i++)\n"
"			{\n"
"				if (i in o)\n"
"				{\n"
"					result.push(console.dump(o[i]));\n"
"				}\n"
"			}\n"
"			return \"[\" + result.join(\", \") + \"]\";\n"
"		}\n"
"		else\n"
"		{\n"
"			if (SadInternalIsNativeObject(o))\n"
"			{\n"
"				if (o.hasOwnProperty('toString'))\n"
"				{\n"
"					return o.toString();\n"
"				} \n"
"				var hasPrototypeToString = false;\n"
"				if (typeof o.prototype != \"undefined\")\n"
"				{\n"
"					hasPrototypeToString = (o.prototype.hasOwnProperty('toString') && o.prototype.toString != Object.toString);\n"
"				}\n"
"				if (hasPrototypeToString)\n"
"				{\n"
"					return o.toString();\n"
"				}\n"
"				return SadInternalDumpNativeObject(o);\n"
"			}\n"
"			else\n"
"			{\n"
"				if (o.hasOwnProperty('toString'))\n"
"				{\n"
"					return o.toString();\n"
"				}\n"
"				else\n"
"				{\n"
"					var asString = o.toString();\n"
"					if (asString != \"[object Object]\")\n"
"					{\n"
"						return asString;\n"
"					}\n"
"					else\n"
"					{\n"
"						var result = [];\n"
"						for(var key in o) { result.push(\"\\\"\" + key + \"\\\"\" + ' : ' + console.dump(o[key]));}\n"
"					}\n"
"				}\n"
"				return \"{\" + result.join(\", \") + \"}\";\n"
"			}\n"
"		}\n"
"	}\n"
"	return \"\";\n"
"};\n"
"\n"
"console.log = function(o)\n"
"{\n"
"	print(console.dump(o));\n"
"};\n"
"\n"
"// sad.util and sad.fs\n"
"sad.fs = {};\n"
"\n"
"sad.fs.pathDelimiter = SadUtilPathDelimiter;\n"
"sad.fs.canonicalizePath = SadUtilCanonicalizePath;\n"
"sad.fs.isAbsolutePath = SadUtilIsAbsolutePath;\n"
"sad.fs.concatPaths = SadUtilConcatPaths;\n"
"sad.fs.folder = SadUtilFolder;\n"
"sad.fs.fileExists = SadUtilFileExists;\n"
"sad.internal.copyObject(sad.util, sad.fs);\n"
"\n"
"// sad.spit and sad.slurp\n"
"\n"
"sad.spit = SadSpit;\n"
"sad.slurp = SadSlurp;\n"
"\n"
"sad.spitJSON = function(a, obj) {\n"
"	return sad.spit(a, JSON.stringify(obj, null, 2));\n"
"};\n"
"\n"
"sad.slurpJSON = function(o) {\n"
"	var	 r = sad.slurp(o);\n"
"	if (r !== null) {\n"
"		return JSON.parse(r);\n"
"	}\n"
"	return null;\n"
"};\n"
"\n"
"\n"
"// context\n"
"\n"
"context.evalFromFile = function(string) {\n"
"	var s = sad.slurp(string);\n"
"	if (s == null) {\n"
"		throw new Error(\"Cannot read file \\\"\" + string + \"\\\"\");\n"
"	}\n"
"	return eval(s);\n"
"};\n"
"\n"
"context.eval = function(string) {\n"
"	return eval(string);\n"
"};\n"
"\n"
"sad.Context = SadContext;\n"
"\n"
"sad.Context.prototype.eval = function(string) {\n"
"	return SadContextEval(this, string);\n"
"};\n"
"\n"
"sad.Context.prototype.evalFromFile = function(string) {\n"
"	return SadContextEvalFromFile(this, string);\n"
"};\n"
"\n"
"// sad.Renderer bindings\n"
"\n"
"sad.Renderer = SadRenderer;\n"
"\n"
"sad.Renderer.ref = SadRendererRef;\n"
"sad.Renderer.makeFPSInterpolationDefault = function() {	 SadInternalMakeFPSInterpolationDefault(this); }\n"
"sad.Renderer.makeFPSInterpolationObjectDependent = function() {	 SadInternalMakeFPSInterpolationObjectDependent(this); }\n"
"\n"
"// sad.Settings bindings\n"
"\n"
"sad.Settings = SadSettings;\n"
"\n"
"// sad.Timer bindings\n"
"\n"
"sad.Timer = SadTimer;\n"
"\n"
"sad.Timer.prototype.elapsedInMs = function() {\n"
"	this.stop();\n"
"	return this.elapsed();\n"
"};\n"
"\n"
"// sad.Thread bindings\n"
"\n"
"sad.Thread = SadThread;\n"
"\n"
"// sad.Color bindings\n"
"\n"
"sad.Color = SadColor;\n"
"\n"
"sad.internal.uCharToInt = function(a) {\n"
"	if (a.length == 0) {\n"
"		return 0;\n"
"	}\n"
"	return a[0].charCodeAt(0);\n"
"}\n"
"\n"
"sad.Color.prototype.toString = function() {\n"
"	var o =	 [ sad.internal.uCharToInt(this.r),	 sad.internal.uCharToInt(this.g), sad.internal.uCharToInt(this.b) ]; \n"
"	return \"sad::Color(\" + o.join(', ')	 + \")\";\n"
"}\n"
"\n"
"sad.AColor = SadAColor;\n"
"\n"
"sad.AColor.prototype.toString = function() {\n"
"	var o =	 [ sad.internal.uCharToInt(this.r),	 sad.internal.uCharToInt(this.g), sad.internal.uCharToInt(this.b), sad.internal.uCharToInt(this.a) ]; \n"
"	return \"sad::AColor(\" + o.join(', ')  + \")\";\n"
"}\n"
"\n"
"// sad.log.Log bindings\n"
"\n"
"sad.log = {};\n"
"sad.log.Log = SadLog;\n"
"sad.log.Log.prototype.ref = SadLogRef;\n"
"sad.log.Log.prototype.addTarget = function(a) { SadInternalLogAddTarget(this, a); }\n"
"sad.log.Log.prototype.removeTarget = function(a) { SadInternalLogRemoveTarget(this, a); }\n"
"\n"
"sad.log.Priority = {\n"
"	\"FATAL\" : 6, \n"
"	\"CRITICAL\" : 5, \n"
"	\"WARNING\" : 4,\n"
"	\"MESSAGE\" : 3, \n"
"	\"DEBUG\" : 2, \n"
"	\"USER\" : 1, \n"
"	\"SADDY_INTERNAL\" : 0  \n"
"};\n"
"\n"
"sad.log.ConsoleTarget = SadLogConsoleTarget;\n"
"sad.log.FileTarget = SadLogFileTarget;\n"
"\n"
"sad.sleep = SadSleep;\n"
"sad.Mutex = SadMutex;\n"
"sad.Semaphore = SadSemaphore;\n"
"\n"
"sad.MouseCursor = SadMouseCursor;\n"
"\n"
"\n"
"sad.resource = {};\n"
"sad.resource.Tree = SadResourceTree;\n"
"\n"
"sad.resource.Tree.prototype.ref = function() {\n"
"	return sad.Renderer.ref().tree(\"\");\n"
"}\n"
"\n"
"sad.db = {};\n"
"sad.db.Database = SadDBDatabase;\n"
"sad.db.Table = SadDBTable;\n"
"\n"
"sad.db.custom = {};\n"
"sad.db.custom.Object = SadDbCustomObject; \n"
"\n"
"sad.db.custom.Object.prototype.getProperty = function(name) {\n"
"	return SadDBCustomObjectGetProperty(this, name);\n"
"};\n"
"\n"
"sad.db.custom.Object.prototype.setProperty = function(name, value) {\n"
"	return SadDBCustomObjectSetProperty(this, name, value);\n"
"};\n"
"\n"
"sad.db.custom.Object.prototype.ownPropertyNames = function() {\n"
"	return SadDBCustomObjectOwnPropertyNames(this);\n"
"};\n"
"\n"
"sad.db.custom.Object.prototype.propertyNames = function() {\n"
"	return SadDBCustomObjectPropertyNames(this);\n"
"};\n"
"\n"
"\n"
"sad.input = {};\n"
"\n"
"sad.input.QuitEvent = SadInputQuitEvent;\n"
"sad.input.MouseLeaveEvent = SadInputMouseLeaveEvent;\n"
"sad.input.ActivateEvent = SadInputActivateEvent;\n"
"sad.input.DeactivateEvent = SadInputDeactivateEvent;\n"
"sad.input.KeyPressEvent = SadInputKeyPressEvent;\n"
"sad.input.KeyReleaseEvent = SadInputKeyReleaseEvent;\n"
"sad.input.MouseMoveEvent = SadInputMouseMoveEvent;\n"
"sad.input.MouseEnterEvent = SadInputMouseEnterEvent;\n"
"sad.input.MousePressEvent = SadInputMousePressEvent;\n"
"sad.input.MouseReleaseEvent = SadInputMouseReleaseEvent;\n"
"sad.input.MouseDoubleClickEvent = SadInputMouseDoubleClickEvent;\n"
"sad.input.MouseWheelEvent = SadInputMouseWheelEvent;\n"
"sad.input.ResizeEvent = SadInputResizeEvent;\n"
"\n"
"sad.KeyboardKey = {\n"
"	\"Numeric0\": 48,\n"
"	\"Numeric1\": 49,\n"
"	\"Numeric2\": 50,\n"
"	\"Numeric3\": 51,\n"
"	\"Numeric4\": 52,\n"
"	\"Numeric5\": 53,\n"
"	\"Numeric6\": 54,\n"
"	\"Numeric7\": 55,\n"
"	\"Numeric8\": 56,\n"
"	\"Numeric9\": 57,\n"
"	\"A\": 65,\n"
"	\"B\": 66,\n"
"	\"C\": 67,\n"
"	\"D\": 68,\n"
"	\"E\": 69,\n"
"	\"F\": 70,\n"
"	\"G\": 71,\n"
"	\"H\": 72,\n"
"	\"I\": 73,\n"
"	\"J\": 74,\n"
"	\"K\": 75,\n"
"	\"L\": 76,\n"
"	\"M\": 77,\n"
"	\"N\": 78,\n"
"	\"O\": 79,\n"
"	\"P\": 80,\n"
"	\"Q\": 81,\n"
"	\"R\": 82,\n"
"	\"S\": 83,\n"
"	\"T\": 84,\n"
"	\"U\": 85,\n"
"	\"V\": 86,\n"
"	\"W\": 87,\n"
"	\"X\": 88,\n"
"	\"Y\": 89,\n"
"	\"Z\": 90,  \n"
"	\"Minus\": 45, \n"
"	\"Equal\": 61,\n"
"	\"BackSlash\": 92, \n"
"	\"Tilde\": 126, \n"
"	\"OpeningSquareBracket\": 91,\n"
"	\"ClosingSquareBracket\": 93,\n"
"	\"Semicolon\": 59,\n"
"	\"Comma\": 44,\n"
"	\"Period\": 46,\n"
"	\"Slash\": 47,\n"
"	\"Apostrophe\": 39,\n"
"	\"Esc\": 256,	 \n"
"	\"F1\" : 257,	 \n"
"	\"F2\" : 258,	 \n"
"	\"F3\" : 259,	 \n"
"	\"F4\" : 260,	 \n"
"	\"F5\" : 261,	 \n"
"	\"F6\" : 262,	 \n"
"	\"F7\" : 263,	 \n"
"	\"F8\" : 264,	 \n"
"	\"F9\" : 265,	 \n"
"	\"F10\": 266,	 \n"
"	\"F11\": 267,	 \n"
"	\"F12\": 268,	 \n"
"	\"Pause\":  269,	\n"
"	\"Insert\": 270,	\n"
"	\"Delete\": 271,	\n"
"	\"Backspace\": 272,  \n"
"	\"Enter\": 273,  \n"
"	\"Space\": 274,  \n"
"	\"PrintScreen\": 275,	 \n"
"	\"Home\": 276,  \n"
"	\"End\": 277,	 \n"
"	\"PageUp\": 278,	\n"
"	\"PageDown\": 279,  \n"
"	\"Tab\": 280,	 \n"
"	\"NumLock\": 281,	 \n"
"	\"ScrollLock\": 282,	\n"
"	\"CapsLock\": 283,  \n"
"	\"WindowsKey\": 284,	\n"
"	\"AppKey\": 285,	\n"
"	\"KeyLeft\": 286,	 \n"
"	\"KeyRight\": 287,  \n"
"	\"KeyUp\": 288,  \n"
"	\"KeyDown\": 289,	 \n"
"	\"LeftShift\": 290,  \n"
"	\"RightShift\": 291,	\n"
"	\"LeftControl\": 292,	 \n"
"	\"RightControl\": 293,  \n"
"	\"LeftAlt\": 294,	 \n"
"	\"RightAlt\": 295,  \n"
"	\"KeyNone\": 296	\n"
"};\n"
"\n"
"sad.MouseButton = {\n"
"	\"MouseLeft\"	  : -16535,\n"
"	\"MouseMiddle\" : -16534,\n"
"	\"MouseRight\"  : -16533,\n"
"	\"MouseNone\"	  : 0\n"
"};\n"
"\n"
"sad.SpecialKey = {\n"
"	\"HoldsControl\" :  -16538,  \n"
"	\"HoldsAlt\"	   :  -16537,  \n"
"	\"HoldsShift\"   :  -16536  \n"
"};\n"
"\n"
"sad.input.EventType = {\n"
"	\"ET_Quit\" : 0,\n"
"	\"ET_Activate\" : 1,\n"
"	\"ET_Deactivate\" : 2,\n"
"	\"ET_MouseEnter\" : 3,\n"
"	\"ET_MouseLeave\" : 4,\n"
"	\"ET_KeyPress\" : 5,\n"
"	\"ET_KeyRelease\" : 6,\n"
"	\"ET_MouseMove\" : 7,\n"
"	\"ET_MousePress\" : 8,\n"
"	\"ET_MouseRelease\" : 9,\n"
"	\"ET_MouseDoubleClick\" : 10,\n"
"	\"ET_MouseWheel\" : 11,\n"
"	\"ET_Resize\" : 12\n"
"};\n"
"\n"
"sad.input.JSControls = SadInputJSControls;\n"
"\n"
"sad.input.JSControls.prototype.onQuit = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_Quit, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onActivate = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_Quit, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onDeactivate = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_Deactivate, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onMouseEnter = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_MouseEnter, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onEnter = sad.input.JSControls.prototype.onMouseEnter ;\n"
"\n"
"sad.input.JSControls.prototype.onMouseLeave = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_MouseLeave, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onLeave = sad.input.JSControls.prototype.onMouseLeave ;\n"
"\n"
"sad.input.JSControls.prototype.onKeyPress = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_KeyPress, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onKeyRelease = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_KeyRelease, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onMouseMove = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_MouseMove, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onMove  = sad.input.JSControls.prototype.onMouseMove;\n"
"\n"
"sad.input.JSControls.prototype.onMousePress = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_MousePress, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onClick = sad.input.JSControls.prototype.onMousePress;\n"
"\n"
"sad.input.JSControls.prototype.onMouseRelease = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_MouseRelease, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onRelease = sad.input.JSControls.prototype.onMouseRelease;\n"
"\n"
"sad.input.JSControls.prototype.onMouseDoubleClick = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_MouseDoubleClick, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onDblClick = sad.input.JSControls.prototype.onMouseDoubleClick;\n"
"\n"
"sad.input.JSControls.prototype.onMouseWheel = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_MouseWheel, ctx, fn);\n"
"};\n"
"\n"
"sad.input.JSControls.prototype.onWheel = sad.input.JSControls.prototype.onMouseWheel;\n"
"\n"
"sad.input.JSControls.prototype.onResize = function(ctx, fn) {\n"
"	return this.onEvent(sad.input.EventType.ET_Resize, ctx, fn);\n"
"};\n"
"\n"
"sad.isValidKeyboardKey = SadIsValidKeyboardKey;\n"
"sad.keyToString = SadIsValidKeyboardKey;\n"
"sad.defaultKeyIfNotValid = SadDefaultKeyIfNotValid;\n"
"\n"
"\n"
"sad.pipeline = function(r) {\n"
"	return {\n"
"		\"r\" : r,\n"
"		\"beforeScene\" : function() {\n"
"			return {\n"
"				\"r\" : this.r,\n"
"				\"eachFrame\": function(step, ctx, fn) { SadPipelineBeforeSceneEachFrame(this.r, step, ctx, fn) },\n"
"				\"eachMS\": function(step, interval, ctx, fn) { SadPipelineBeforeSceneEachMS(this.r, step, interval, ctx, fn) },\n"
"				\"oneShot\": function(step, ctx, fn) { SadPipelineBeforeSceneOneShot(this.r, step, ctx, fn) },\n"
"				\"delayed\": function(step, interval, ctx, fn) { SadPipelineBeforeSceneDelayed(this.r, step, interval, ctx, fn) }\n"
"			};\n"
"		},\n"
"		\"afterScene\" : function() {\n"
"			return {\n"
"				\"r\" : this.r,\n"
"				\"eachFrame\": function(step, ctx, fn) { SadPipelineAfterSceneEachFrame(this.r, step, ctx, fn) },\n"
"				\"eachMS\": function(step, interval, ctx, fn) { SadPipelineAfterSceneEachMS(this.r, step, interval, ctx, fn) },\n"
"				\"oneShot\": function(step, ctx, fn) { SadPipelineAfterSceneOneShot(this.r, step, ctx, fn) },\n"
"				\"delayed\": function(step, interval, ctx, fn) { SadPipelineAfterSceneDelayed(this.r, step, interval, ctx, fn) }\n"
"			};\n"
"		},\n"
"		\"beforeEvent\" : function(ev) {\n"
"			return {\n"
"				\"r\" : this.r,\n"
"				\"ev\" : ev, \n"
"				\"eachFrame\": function(step, ctx, fn) { SadPipelineBeforeEventEachFrame(this.r, this.ev, step, ctx, fn) },\n"
"				\"eachMS\": function(step, interval, ctx, fn) { SadPipelineBeforeEventEachMS(this.r, this.ev, step, interval, ctx, fn) },\n"
"				\"oneShot\": function(step, ctx, fn) { SadPipelineBeforeEventOneShot(this.r, this.ev, step, ctx, fn) },\n"
"				\"delayed\": function(step, interval, ctx, fn) { SadPipelineBeforeEventDelayed(this.r, this.ev, step, interval, ctx, fn) }\n"
"			};\n"
"		},\n"
"		\"afterEvent\" : function(ev) {\n"
"			return {\n"
"				\"r\" : this.r,\n"
"				\"ev\" : ev, \n"
"				\"eachFrame\": function(step, ctx, fn) { SadPipelineAfterEventEachFrame(this.r, this.ev, step, ctx, fn) },\n"
"				\"eachMS\": function(step, interval, ctx, fn) { SadPipelineAfterEventEachMS(this.r, this.ev, step, interval, ctx, fn) },\n"
"				\"oneShot\": function(step, ctx, fn) { SadPipelineAfterEventOneShot(this.r, this.ev, step, ctx, fn) },\n"
"				\"delayed\": function(step, interval, ctx, fn) { SadPipelineAfterEventDelayed(this.r, this.ev, step, interval, ctx, fn) }\n"
"			};\n"
"		}\n"
"	};\n"
"};\n"
"\n"
"sad.Camera = SadCamera;\n"
"\n"
"sad.Camera.prototype.move = function(o) {\n"
"	if (typeof o['z'] != \"undefined\") {\n"
"		this.move3d(o);\n"
"	} else {\n"
"		this.move2d(o);\n"
"	}\n"
"}\n"
"\n"
"sad.OrthographicCamera = SadOrthographicCamera;\n"
"\n"
"sad.OrthographicCamera.prototype.move = function(o) {\n"
"	if (typeof o['z'] != \"undefined\") {\n"
"		this.move3d(o);\n"
"	} else {\n"
"		this.move2d(o);\n"
"	}\n"
"}\n"
"\n"
"sad.Scene = SadScene;\n"
"sad.Sprite3D = SadSprite3D;\n"
"\n"
"sad.Label = SadLabel;\n"
"\n"
"sad.Label.OverflowStrategy = {\n"
"	\"LOS_VISIBLE\" : 0,\n"
"	\"LOS_HIDDEN\" : 1,\n"
"	\"LOS_ELLIPSIS\" : 2\n"
"};\n"
"\n"
"sad.Label.BreakText = {\n"
"	\"LBT_NORMAL\" : 0,\n"
"	\"LBT_BREAK_WORD\" : 1\n"
"};\n"
"\n"
"sad.Label.TextEllipsisPosition = {\n"
"	\"LTEP_BEGIN\" : 0,\n"
"	\"LTEP_MIDDLE\" : 1,\n"
"	\"LTEP_END\" : 2\n"
"};\n"
"\n"
"sad.Label.prototype.setFont = function(font, r, tree) {\n"
"	return SadLabelSetFont(this, font, r, tree);\n"
"};\n"
"\n"
"sad.Sprite2D = SadSprite2D;\n"
"sad.Sprite2D.Options = SadSprite2DOptions;\n"
"\n"
"sad.p2d = {};\n"
"\n"
"sad.p2d.BoundType = {\n"
"	\"BT_LEFT\" : 0,\n"
"	\"BT_RIGHT\" : 1,\n"
"	\"BT_DOWN\" : 2,\n"
"	\"BT_UP\" : 3\n"
"};\n"
"\n"
"sad.p2d.Bound = function(type, position) {\n"
"	if (typeof type == \"undefined\") {\n"
"		type = sad.p2d.BoundType.BT_LEFT;\n"
"	}\n"
"	if (typeof position == \"undefined\") {\n"
"		position = 0;\n"
"	}\n"
"	if ((type < 0) || (type > 3)) {\n"
"		throw new TypeError(\"Argument 0 is not a sad::p2d::BoundType\");\n"
"	}\n"
"	this.type = type;\n"
"	this.position = position;\n"
"	this.clone =  function() {\n"
"		return new sad.p2d.Bound(this.type, this.position);\n"
"	};\n"
"	this.center = function() {\n"
"		return new sad.Point2D(0,0);\n"
"	};\n"
"	this.rotate = function(angle) {\n"
"		\n"
"	};\n"
"	this.move = function(v) {\n"
"		\n"
"	};\n"
"	this.dump = function() {\n"
"		var b =	 [\"Left\", \"Right\", \"Bottom\", \"Top\"];\n"
"		return b[this.type] + \" bound at \" + this.position;\n"
"	};\n"
"};\n"
"\n"
"sad.p2d.isPoint2D = function(o) {\n"
"	if (typeof o == \"object\") {\n"
"		if (o != null) {\n"
"			if (typeof o[\"x\"] == \"number\" && typeof o[\"y\"] == \"number\") {\n"
"				return true;\n"
"			}\n"
"		}\n"
"	}\n"
"	return false;\n"
"};\n"
"\n"
"sad.p2d.isRect2D = function(o) {\n"
"	try {\n"
"		return SadP2DRect2D(o);\n"
"	} catch(ex) {\n"
"		\n"
"	}\n"
"	return false;\n"
"};\n"
"\n"
"sad.p2d.Matrix2x2 = {};\n"
"\n"
"sad.p2d.Matrix2x2.counterclockwise = function(angle) {\n"
"	var m = [[0,0], [0], [0]];\n"
"	var cos = Math.cos(angle);\n"
"	var sin = Math.sin(angle);\n"
"	m[0][0] = cos; m[1][1] = cos;\n"
"	m[0][1] = (-1) * sin; m[1][0] = sin;\n"
"	return m;\n"
"};\n"
"\n"
"sad.p2d.Matrix2x2.multiply = function(m, p) {\n"
"	var x = p.x * m[0][0] \n"
"		  + p.y * m[1][0];\n"
"	var y = p.x * m[0][1] \n"
"		  + p.y * m[1][1];\n"
"	return new sad.Point2D(x, y);\n"
"};\n"
"\n"
"sad.p2d.Line = function(cx1, cy1, cx2, cy2) {\n"
"	var isconstructorcall = true;\n"
"	this.clone = function() {\n"
"		return new sad.p2d.Line([this.m_c[0].clone(), this.m_c[1].clone()]);\n"
"	};\n"
"	this.setCutter = function(x1,y1,x2,y2) {\n"
"		var cerror = true;\n"
"		if (typeof x2 == \"undefined\" && typeof y2 ==\"undefined\") {\n"
"			if (typeof x1 == \"undefined\" && typeof y1 == \"undefined\") {\n"
"				this.m_c = [new sad.Point2D(0, 0), new sad.Point2D(0, 0)];\n"
"				cerror = false;\n"
"			} else {\n"
"				if (typeof x1 != \"undefined\" && typeof y1 == \"undefined\") {\n"
"					var error = true;\n"
"					cerror = false;\n"
"					if (x1 instanceof Array) {\n"
"						if (x1.length == 2) {\n"
"							if (sad.p2d.isPoint2D(x1[0]) && sad.p2d.isPoint2D(x1[1])) {\n"
"									error = false;\n"
"									this.m_c = x1;\n"
"							}\n"
"						}\n"
"					} \n"
"					if (error) {\n"
"						throw new TypeError(\"Argument 0 is not a sad::p2d::Cutter2D instance\");\n"
"					}\n"
"				} else {\n"
"					if (typeof x1 != \"undefined\"  && typeof y1 != \"undefined\") {\n"
"						cerror = false;\n"
"						if (sad.p2d.isPoint2D(x1) && sad.p2d.isPoint2D(y1)) { \n"
"							this.m_c = [x1, y1];\n"
"						} else {\n"
"							throw new TypeError(\"Arguments 0 and 1 must have type sad::Point2D\");\n"
"						}\n"
"					}\n"
"				}\n"
"			}\n"
"		} else {\n"
"			if (typeof x1  == \"number\" && typeof y1	 == \"number\" && typeof x2  == \"number\" && typeof y2	 == \"number\") {\n"
"				cerror = false;\n"
"				this.m_c = [ new sad.Point2D(x1, y1), new sad.Point2D(x2, y2)];\n"
"			}\n"
"		}\n"
"		if (cerror) {\n"
"			if (isconstructorcall) {\n"
"				throw new TypeError(\"Could not match call arguments for sad.p2d.Line constructor\");\n"
"			} else {\n"
"				throw new TypeError(\"Could not match call arguments for sad.p2d.Line.setCutter\");\n"
"			}\n"
"		}\n"
"	};\n"
"	this.cutter = function() {\n"
"		return this.m_c;\n"
"	};\n"
"	this.center = function() {\n"
"		return new sad.Point2D((this.m_c[0].x + this.m_c[1].x) / 2.0, (this.m_c[0].y + this.m_c[1].y) / 2.0);\n"
"	};\n"
"	this.move = function(d) {\n"
"		if (sad.p2d.isPoint2D(d)) {\n"
"			this.m_c[0] = new sad.Point2D(this.m_c[0].x + d.x, this.m_c[0].y + d.y);\n"
"			this.m_c[1] = new sad.Point2D(this.m_c[1].x + d.x, this.m_c[1].y + d.y);\n"
"		} else {\n"
"			throw new TypeError(\"Could not match argument 1 with type sad::Point2D\");\n"
"		}\n"
"	};\n"
"	this.rotate = function(angle) {\n"
"		if (typeof angle == \"number\") {\n"
"			var center = this.center();\n"
"			var centerdp1 = this.m_c[0].minus(center);\n"
"			var centerdp2 = this.m_c[1].minus(center);\n"
"			var m = sad.p2d.Matrix2x2.counterclockwise(angle);\n"
"			var x1 = sad.p2d.Matrix2x2.multiply(m, centerdp1).plus(center);\n"
"			var x2 = sad.p2d.Matrix2x2.multiply(m, centerdp2).plus(center);\n"
"			this.m_c = [x1, x2];\n"
"		} else {\n"
"			throw new TypeError(\"Could not match argument 1 with type double\");\n"
"		}\n"
"	}\n"
"	this.p1 = function() {\n"
"		return this.m_c[0];\n"
"	};\n"
"	this.p2 = function() {\n"
"		return this.m_c[1];\n"
"	};\n"
"	this.setP1 = function(d) {\n"
"		if (sad.p2d.isPoint2D(d)) {\n"
"			this.m_c[0] = d;\n"
"		} else {\n"
"			throw new TypeError(\"Could not match argument 1 with type sad::Point2D\");\n"
"		}\n"
"	};\n"
"	this.setP2 = function(d) {\n"
"		if (sad.p2d.isPoint2D(d)) {\n"
"			this.m_c[1] = d;\n"
"		} else {\n"
"			throw new TypeError(\"Could not match argument 1 with type sad::Point2D\");\n"
"		}\n"
"	};\n"
"	this.dump = function() {\n"
"		return \"Line at (\" + this.m_c[0].x + \", \" + this.m_c[0].y + \") - (\" + this.m_c[1].x + \", \" + this.m_c[1].y + \")\";\n"
"	}\n"
"	this.resizeBy = function(v) {\n"
"		if (sad.p2d.isPoint2D(v)) {\n"
"			var n = this.p2().minus(this.p1());\n"
"			n = sad.p2d.unit(n); \n"
"			var length = sad.p2d.scalar(n, v);\n"
"			var vec = new sad.Point2D(n.x * length, n.y * length);\n"
"			this.m_c[1] = this.m_c[1].plus(vec);\n"
"			this.m_c[0] = this.m_c[0].minus(vec);\n"
"		} else {\n"
"			throw new TypeError(\"Could not match argument 1 with type sad::Point2D\");\n"
"		}\n"
"	};\n"
"	\n"
"	\n"
"	this.setCutter(cx1, cy1, cx2, cy2);\n"
"	isconstructorcall = false;\n"
"};\n"
"\n"
"sad.p2d.Rectangle = function(o) {\n"
"	this.clone = function() {\n"
"		return new sad.p2d.Rectangle(this.m_rect.clone());\n"
"	};\n"
"	this.setRect = function(o) {\n"
"		if (sad.p2d.isRect2D(o)) {\n"
"			this.m_rect = o;\n"
"		} else {\n"
"			throw new TypeError(\"Argument 0 is not a sad::Rect2D\");\n"
"		}\n"
"	};\n"
"	this.point = function(i) {\n"
"		if (typeof i == \"number\") {\n"
"			if (i > -1 && i < 4) {\n"
"				return  this.m_rect[\"p\" + i]();\n"
"			} else {\n"
"				throw new TypeError(\"Please, specify value in [0..3] range\")\n"
"			}\n"
"		} else {\n"
"			throw new TypeError(\"Argument 0 is not a number\");\n"
"		}\n"
"	};\n"
"	this.points = function() {\n"
"		return [this.m_rect.p0(), this.m_rect.p1(), this.m_rect.p2(), this.m_rect.p3()];\n"
"	};\n"
"	this.rect = function() {\n"
"		return this.m_rect;\n"
"	};\n"
"	this.center = function() {\n"
"		var p1 = this.m_rect.p0();\n"
"		var p2 = this.m_rect.p2();\n"
"		return new sad.Point2D((p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0);\n"
"	};\n"
"	this.rotate = function(angle) {\n"
"		if (typeof angle == \"number\") {\n"
"			this.m_rect = sad.rotate(this.m_rect, angle);\n"
"		} else {\n"
"			throw new TypeError(\"Argument 0 is not a number\");\n"
"		} \n"
"	};\n"
"	this.moveBy = function(d) {\n"
"		if (sad.p2d.isPoint2D(d)) {\n"
"			this.m_rect = sad.moveBy(d, this.m_rect);\n"
"		} else {\n"
"			throw new TypeError(\"Argument 0 is not a sad::Point2D\");\n"
"		}\n"
"	};\n"
"	this.dump = function(o) {\n"
"		var pts = this.points();\n"
"		return \"Rectangle:\\n[{0}, {1} - {2}, {3}]\\n[{4}, {5} - {6}, {7}]\\n\"\n"
"				.replace(\"{0}\", pts[0].x)\n"
"				.replace(\"{1}\", pts[0].y)\n"
"				.replace(\"{2}\", pts[1].x)\n"
"				.replace(\"{3}\", pts[1].y)\n"
"				.replace(\"{4}\", pts[3].x)\n"
"				.replace(\"{5}\", pts[3].y)\n"
"				.replace(\"{6}\", pts[2].x)\n"
"				.replace(\"{7}\", pts[2].y);\n"
"	};\n"
"	this.resizeBy = function(v) {\n"
"		var sum = function(p, cx, cy) {\n"
"			return p.plus( new sad.Point2D(v.x * cx, v.y * cy) );\n"
"		};\n"
"		var pts = this.points();\n"
"		if (sad.p2d.isPoint2D(v)) {\n"
"			pts[0] = sum(pts[0], -1, -1);\n"
"			pts[1] = sum(pts[1], 1, -1);\n"
"			pts[2] = sum(pts[2], 1, 1);\n"
"			pts[3] = sum(pts[3], -1, 1);\n"
"			this.setRect(new sad.Rect2D(pts[0], pts[1], pts[2], pts[3]));\n"
"		} else {\n"
"			throw new TypeError(\"Argument 0 is not a sad::Point2D\");\n"
"		}\n"
"	};\n"
"	if (typeof o == \"undefined\") {\n"
"		o = new sad.Rect2D();\n"
"	}\n"
"	this.setRect(o);\n"
"};\n"
"\n"
"\n"
"sad.p2d.Circle = function(center, radius) {\n"
"	if (typeof center == \"undefined\") {\n"
"		center = new sad.Point2D(0, 0);\n"
"	};\n"
"	if (typeof radius == \"undefined\") {\n"
"		radius = 0;\n"
"	};\n"
"	this.clone = function() {\n"
"		return new sad.p2d.Circle(this.m_center.clone(), this.m_radius);\n"
"	};\n"
"	this.center = function() {\n"
"		return this.m_center;\n"
"	};\n"
"	this.centerRef = this.center;\n"
"	this.radius = function() {\n"
"		return this.m_radius;\n"
"	};\n"
"	this.setCenter =  function(p) {\n"
"		if (sad.p2d.isPoint2D(p)) {\n"
"			this.m_center = p;\n"
"		} else {\n"
"			throw new TypeError(\"Argument 0 is not a sad::Point2D\");\n"
"		}\n"
"	};\n"
"	this.setRadius = function(radius) {\n"
"		if (typeof radius == \"number\") {\n"
"			this.m_radius = radius;\n"
"		} else {\n"
"			throw new TypeError(\"Argument 0 is not a number\");\n"
"		} \n"
"	};\n"
"	this.rotate = function(angle) {\n"
"		if (typeof angle != \"number\") {\n"
"			throw new TypeError(\"Argument 0 is not a number\");\n"
"		} \n"
"	};\n"
"	this.moveBy = function(d) {\n"
"		if (sad.p2d.isPoint2D(d)) {\n"
"			this.m_center = new sad.Point2D(this.m_center.x + d.x, this.m_center.y + d.y);\n"
"		} else {\n"
"			throw new TypeError(\"Argument 0 is not a sad::Point2D\");\n"
"		}\n"
"	};\n"
"	this.move = this.moveBy;\n"
"	this.dump = function(o) {\n"
"		return \"Circle with center (\" + this.m_center.x +\",\" +  + this.m_center.y + \") and radius \" + this.m_radius;\n"
"	};\n"
"	this.resizeBy = function(v) {\n"
"		if (sad.p2d.isPoint2D(v)) {\n"
"			var modulo = sad.p2d.modulo(v);\n"
"			if (v.x > 0 || v.y > 0) {\n"
"				this.m_radius += modulo;\n"
"			} else {\n"
"				this.m_radius -= modulo;\n"
"			}\n"
"		} else {\n"
"			throw new TypeError(\"Argument 0 is not a sad::Point2D\");\n"
"		}\n"
"	};\n"
"	this.setCenter(center);\n"
"	this.setRadius(radius);\n"
"};\n");