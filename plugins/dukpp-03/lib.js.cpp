#include<string>
extern const std::string __context_eval_info;
const std::string __context_eval_info = std::string("var sad = {};\n"
"sad.internal = {};\n"
"sad.Point2D = SadPoint2D;\n"
"sad.Point3D = SadPoint3D;\n"
"\n"
"sad.internal.plus = function(a, b) { return a + b; };\n"
"sad.internal.minus = function(a, b) { return a - b; };\n"
"sad.internal.multiply = function(a, b) { return a * b; };\n"
"sad.internal.divide = function(a, b) { return a / b; };\n"
"\n"
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
"//  sad.Point2D bindings\n"
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
"//  sad.Point3D bindings\n"
"\n"
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
"};\n");