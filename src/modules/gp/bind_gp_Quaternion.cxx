/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Quaternion.hxx>
#include <gp_Vec.hxx>
#include <gp_Mat.hxx>
#include <gp_EulerSequence.hxx>

void bind_gp_Quaternion(py::module &mod){

py::class_<gp_Quaternion> cls_gp_Quaternion(mod, "gp_Quaternion", "Represents operation of rotation in 3d space as queternion and implements operations with rotations basing on quaternion mathematics.");

// Constructors
cls_gp_Quaternion.def(py::init<>());
cls_gp_Quaternion.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_gp_Quaternion.def(py::init<const gp_Quaternion &>(), py::arg("theToCopy"));
cls_gp_Quaternion.def(py::init<const gp_Vec &, const gp_Vec &>(), py::arg("theVecFrom"), py::arg("theVecTo"));
cls_gp_Quaternion.def(py::init<const gp_Vec &, const gp_Vec &, const gp_Vec &>(), py::arg("theVecFrom"), py::arg("theVecTo"), py::arg("theHelpCrossVec"));
cls_gp_Quaternion.def(py::init<const gp_Vec &, const Standard_Real>(), py::arg("theAxis"), py::arg("theAngle"));
cls_gp_Quaternion.def(py::init<const gp_Mat &>(), py::arg("theMat"));

// Fields

// Methods
// cls_gp_Quaternion.def_static("operator new_", (void * (*)(size_t)) &gp_Quaternion::operator new, "None", py::arg("theSize"));
// cls_gp_Quaternion.def_static("operator delete_", (void (*)(void *)) &gp_Quaternion::operator delete, "None", py::arg("theAddress"));
// cls_gp_Quaternion.def_static("operator new[]_", (void * (*)(size_t)) &gp_Quaternion::operator new[], "None", py::arg("theSize"));
// cls_gp_Quaternion.def_static("operator delete[]_", (void (*)(void *)) &gp_Quaternion::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Quaternion.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Quaternion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Quaternion.def_static("operator delete_", (void (*)(void *, void *)) &gp_Quaternion::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Quaternion.def("IsEqual", (Standard_Boolean (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::IsEqual, "Simple equal test without precision", py::arg("theOther"));
cls_gp_Quaternion.def("SetRotation", (void (gp_Quaternion::*)(const gp_Vec &, const gp_Vec &)) &gp_Quaternion::SetRotation, "Sets quaternion to shortest-arc rotation producing vector theVecTo from vector theVecFrom. If vectors theVecFrom and theVecTo are opposite then rotation axis is computed as theVecFrom ^ (1,0,0) or theVecFrom ^ (0,0,1).", py::arg("theVecFrom"), py::arg("theVecTo"));
cls_gp_Quaternion.def("SetRotation", (void (gp_Quaternion::*)(const gp_Vec &, const gp_Vec &, const gp_Vec &)) &gp_Quaternion::SetRotation, "Sets quaternion to shortest-arc rotation producing vector theVecTo from vector theVecFrom. If vectors theVecFrom and theVecTo are opposite then rotation axis is computed as theVecFrom ^ theHelpCrossVec.", py::arg("theVecFrom"), py::arg("theVecTo"), py::arg("theHelpCrossVec"));
cls_gp_Quaternion.def("SetVectorAndAngle", (void (gp_Quaternion::*)(const gp_Vec &, const Standard_Real)) &gp_Quaternion::SetVectorAndAngle, "Create a unit quaternion from Axis+Angle representation", py::arg("theAxis"), py::arg("theAngle"));
cls_gp_Quaternion.def("GetVectorAndAngle", [](gp_Quaternion &self, gp_Vec & theAxis, Standard_Real & theAngle){ self.GetVectorAndAngle(theAxis, theAngle); return theAngle; }, "Convert a quaternion to Axis+Angle representation, preserve the axis direction and angle from -PI to +PI", py::arg("theAxis"), py::arg("theAngle"));
cls_gp_Quaternion.def("SetMatrix", (void (gp_Quaternion::*)(const gp_Mat &)) &gp_Quaternion::SetMatrix, "Create a unit quaternion by rotation matrix matrix must contain only rotation (not scale or shear)", py::arg("theMat"));
cls_gp_Quaternion.def("GetMatrix", (gp_Mat (gp_Quaternion::*)() const) &gp_Quaternion::GetMatrix, "Returns rotation operation as 3*3 matrix");
cls_gp_Quaternion.def("SetEulerAngles", (void (gp_Quaternion::*)(const gp_EulerSequence, const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Quaternion::SetEulerAngles, "Create a unit quaternion representing rotation defined by generalized Euler angles", py::arg("theOrder"), py::arg("theAlpha"), py::arg("theBeta"), py::arg("theGamma"));
cls_gp_Quaternion.def("GetEulerAngles", [](gp_Quaternion &self, const gp_EulerSequence theOrder, Standard_Real & theAlpha, Standard_Real & theBeta, Standard_Real & theGamma){ self.GetEulerAngles(theOrder, theAlpha, theBeta, theGamma); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theAlpha, theBeta, theGamma); }, "Returns Euler angles describing current rotation", py::arg("theOrder"), py::arg("theAlpha"), py::arg("theBeta"), py::arg("theGamma"));
cls_gp_Quaternion.def("Set", (void (gp_Quaternion::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Quaternion::Set, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_gp_Quaternion.def("Set", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::Set, "None", py::arg("theQuaternion"));
cls_gp_Quaternion.def("X", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::X, "None");
cls_gp_Quaternion.def("Y", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::Y, "None");
cls_gp_Quaternion.def("Z", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::Z, "None");
cls_gp_Quaternion.def("W", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::W, "None");
cls_gp_Quaternion.def("SetIdent", (void (gp_Quaternion::*)()) &gp_Quaternion::SetIdent, "Make identity quaternion (zero-rotation)");
cls_gp_Quaternion.def("Reverse", (void (gp_Quaternion::*)()) &gp_Quaternion::Reverse, "Reverse direction of rotation (conjugate quaternion)");
cls_gp_Quaternion.def("Reversed", (gp_Quaternion (gp_Quaternion::*)() const) &gp_Quaternion::Reversed, "Return rotation with reversed direction (conjugated quaternion)");
cls_gp_Quaternion.def("Invert", (void (gp_Quaternion::*)()) &gp_Quaternion::Invert, "Inverts quaternion (both rotation direction and norm)");
cls_gp_Quaternion.def("Inverted", (gp_Quaternion (gp_Quaternion::*)() const) &gp_Quaternion::Inverted, "Return inversed quaternion q^-1");
cls_gp_Quaternion.def("SquareNorm", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::SquareNorm, "Returns square norm of quaternion");
cls_gp_Quaternion.def("Norm", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::Norm, "Returns norm of quaternion");
cls_gp_Quaternion.def("Scale", (void (gp_Quaternion::*)(const Standard_Real)) &gp_Quaternion::Scale, "Scale all components by quaternion by theScale; note that rotation is not changed by this operation (except 0-scaling)", py::arg("theScale"));
cls_gp_Quaternion.def("__imul__", (void (gp_Quaternion::*)(const Standard_Real)) &gp_Quaternion::operator*=, py::is_operator(), "None", py::arg("theScale"));
cls_gp_Quaternion.def("Scaled", (gp_Quaternion (gp_Quaternion::*)(const Standard_Real) const) &gp_Quaternion::Scaled, "Returns scaled quaternion", py::arg("theScale"));
cls_gp_Quaternion.def("__mul__", (gp_Quaternion (gp_Quaternion::*)(const Standard_Real) const) &gp_Quaternion::operator*, py::is_operator(), "None", py::arg("theScale"));
cls_gp_Quaternion.def("StabilizeLength", (void (gp_Quaternion::*)()) &gp_Quaternion::StabilizeLength, "Stabilize quaternion length within 1 - 1/4. This operation is a lot faster than normalization and preserve length goes to 0 or infinity");
cls_gp_Quaternion.def("Normalize", (void (gp_Quaternion::*)()) &gp_Quaternion::Normalize, "Scale quaternion that its norm goes to 1. The appearing of 0 magnitude or near is a error, so we can be sure that can divide by magnitude");
cls_gp_Quaternion.def("Normalized", (gp_Quaternion (gp_Quaternion::*)() const) &gp_Quaternion::Normalized, "Returns quaternion scaled so that its norm goes to 1.");
cls_gp_Quaternion.def("Negated", (gp_Quaternion (gp_Quaternion::*)() const) &gp_Quaternion::Negated, "Returns quaternion with all components negated. Note that this operation does not affect neither rotation operator defined by quaternion nor its norm.");
cls_gp_Quaternion.def("__sub__", (gp_Quaternion (gp_Quaternion::*)() const) &gp_Quaternion::operator-, py::is_operator(), "None");
cls_gp_Quaternion.def("Added", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::Added, "Makes sum of quaternion components; result is 'rotations mix'", py::arg("theOther"));
cls_gp_Quaternion.def("__add__", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::operator+, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Subtracted", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::Subtracted, "Makes difference of quaternion components; result is 'rotations mix'", py::arg("theOther"));
cls_gp_Quaternion.def("__sub__", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::operator-, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Multiplied", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::Multiplied, "Multiply function - work the same as Matrices multiplying. qq' = (cross(v,v') + wv' + w'v, ww' - dot(v,v')) Result is rotation combination: q' than q (here q=this, q'=theQ). Notices than: qq' != q'q; qq^-1 = q;", py::arg("theOther"));
cls_gp_Quaternion.def("__mul__", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::operator*, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Add", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::Add, "Adds componnets of other quaternion; result is 'rotations mix'", py::arg("theOther"));
cls_gp_Quaternion.def("__iadd__", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::operator+=, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Subtract", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::Subtract, "Subtracts componnets of other quaternion; result is 'rotations mix'", py::arg("theOther"));
cls_gp_Quaternion.def("__isub__", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::operator-=, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Multiply", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::Multiply, "Adds rotation by multiplication", py::arg("theOther"));
cls_gp_Quaternion.def("__imul__", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::operator*=, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Dot", (Standard_Real (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::Dot, "Computes inner product / scalar product / Dot", py::arg("theOther"));
cls_gp_Quaternion.def("GetRotationAngle", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::GetRotationAngle, "Return rotation angle from -PI to PI");
cls_gp_Quaternion.def("Multiply", (gp_Vec (gp_Quaternion::*)(const gp_Vec &) const) &gp_Quaternion::Multiply, "Rotates vector by quaternion as rotation operator", py::arg("theVec"));
cls_gp_Quaternion.def("__mul__", (gp_Vec (gp_Quaternion::*)(const gp_Vec &) const) &gp_Quaternion::operator*, py::is_operator(), "None", py::arg("theVec"));

// Enums

}