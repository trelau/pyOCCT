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
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box2d.hxx>
#include <gp_Trsf2d.hxx>

void bind_Bnd_Box2d(py::module &mod){

py::class_<Bnd_Box2d> cls_Bnd_Box2d(mod, "Bnd_Box2d", "Describes a bounding box in 2D space. A bounding box is parallel to the axes of the coordinates system. If it is finite, it is defined by the two intervals: - [ Xmin,Xmax ], and - [ Ymin,Ymax ]. A bounding box may be infinite (i.e. open) in one or more directions. It is said to be: - OpenXmin if it is infinite on the negative side of the 'X Direction'; - OpenXmax if it is infinite on the positive side of the 'X Direction'; - OpenYmin if it is infinite on the negative side of the 'Y Direction'; - OpenYmax if it is infinite on the positive side of the 'Y Direction'; - WholeSpace if it is infinite in all four directions. In this case, any point of the space is inside the box; - Void if it is empty. In this case, there is no point included in the box. A bounding box is defined by four bounds (Xmin, Xmax, Ymin and Ymax) which limit the bounding box if it is finite, six flags (OpenXmin, OpenXmax, OpenYmin, OpenYmax, WholeSpace and Void) which describe the bounding box if it is infinite or empty, and - a gap, which is included on both sides in any direction when consulting the finite bounds of the box.");

// Constructors
cls_Bnd_Box2d.def(py::init<>());

// Fields

// Methods
// cls_Bnd_Box2d.def_static("operator new_", (void * (*)(size_t)) &Bnd_Box2d::operator new, "None", py::arg("theSize"));
// cls_Bnd_Box2d.def_static("operator delete_", (void (*)(void *)) &Bnd_Box2d::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_Box2d.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_Box2d::operator new[], "None", py::arg("theSize"));
// cls_Bnd_Box2d.def_static("operator delete[]_", (void (*)(void *)) &Bnd_Box2d::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_Box2d.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_Box2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_Box2d.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_Box2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_Box2d.def("SetWhole", (void (Bnd_Box2d::*)()) &Bnd_Box2d::SetWhole, "Sets this bounding box so that it covers the whole 2D space, i.e. it is infinite in all directions.");
cls_Bnd_Box2d.def("SetVoid", (void (Bnd_Box2d::*)()) &Bnd_Box2d::SetVoid, "Sets this 2D bounding box so that it is empty. All points are outside a void box.");
cls_Bnd_Box2d.def("Set", (void (Bnd_Box2d::*)(const gp_Pnt2d &)) &Bnd_Box2d::Set, "Sets this 2D bounding box so that it bounds the point P. This involves first setting this bounding box to be void and then adding the point PThe rectangle bounds the point <P>.", py::arg("thePnt"));
cls_Bnd_Box2d.def("Set", (void (Bnd_Box2d::*)(const gp_Pnt2d &, const gp_Dir2d &)) &Bnd_Box2d::Set, "Sets this 2D bounding box so that it bounds the half-line defined by point P and direction D, i.e. all points M defined by M=P+u*D, where u is greater than or equal to 0, are inside the bounding area. This involves first setting this 2D box to be void and then adding the half-line.", py::arg("thePnt"), py::arg("theDir"));
cls_Bnd_Box2d.def("Update", (void (Bnd_Box2d::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Bnd_Box2d::Update, "Enlarges this 2D bounding box, if required, so that it contains at least: - interval [ aXmin,aXmax ] in the 'X Direction', - interval [ aYmin,aYmax ] in the 'Y Direction'", py::arg("aXmin"), py::arg("aYmin"), py::arg("aXmax"), py::arg("aYmax"));
cls_Bnd_Box2d.def("Update", (void (Bnd_Box2d::*)(const Standard_Real, const Standard_Real)) &Bnd_Box2d::Update, "Adds a point of coordinates (X,Y) to this bounding box.", py::arg("X"), py::arg("Y"));
cls_Bnd_Box2d.def("GetGap", (Standard_Real (Bnd_Box2d::*)() const) &Bnd_Box2d::GetGap, "Returns the gap of this 2D bounding box.");
cls_Bnd_Box2d.def("SetGap", (void (Bnd_Box2d::*)(const Standard_Real)) &Bnd_Box2d::SetGap, "Set the gap of this 2D bounding box to abs(Tol).", py::arg("Tol"));
cls_Bnd_Box2d.def("Enlarge", (void (Bnd_Box2d::*)(const Standard_Real)) &Bnd_Box2d::Enlarge, "Enlarges the box with a tolerance value. This means that the minimum values of its X and Y intervals of definition, when they are finite, are reduced by the absolute value of Tol, while the maximum values are increased by the same amount.", py::arg("theTol"));
cls_Bnd_Box2d.def("Get", [](Bnd_Box2d &self, Standard_Real & aXmin, Standard_Real & aYmin, Standard_Real & aXmax, Standard_Real & aYmax){ self.Get(aXmin, aYmin, aXmax, aYmax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(aXmin, aYmin, aXmax, aYmax); }, "Returns the bounds of this 2D bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). if IsVoid()", py::arg("aXmin"), py::arg("aYmin"), py::arg("aXmax"), py::arg("aYmax"));
cls_Bnd_Box2d.def("OpenXmin", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenXmin, "The Box will be infinitely long in the Xmin direction.");
cls_Bnd_Box2d.def("OpenXmax", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenXmax, "The Box will be infinitely long in the Xmax direction.");
cls_Bnd_Box2d.def("OpenYmin", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenYmin, "The Box will be infinitely long in the Ymin direction.");
cls_Bnd_Box2d.def("OpenYmax", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenYmax, "The Box will be infinitely long in the Ymax direction.");
cls_Bnd_Box2d.def("IsOpenXmin", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsOpenXmin, "Returns true if this bounding box is open in the Xmin direction.");
cls_Bnd_Box2d.def("IsOpenXmax", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsOpenXmax, "Returns true if this bounding box is open in the Xmax direction.");
cls_Bnd_Box2d.def("IsOpenYmin", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsOpenYmin, "Returns true if this bounding box is open in the Ymin direction.");
cls_Bnd_Box2d.def("IsOpenYmax", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsOpenYmax, "Returns true if this bounding box is open in the Ymax direction.");
cls_Bnd_Box2d.def("IsWhole", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsWhole, "Returns true if this bounding box is infinite in all 4 directions (Whole Space flag).");
cls_Bnd_Box2d.def("IsVoid", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsVoid, "Returns true if this 2D bounding box is empty (Void flag).");
cls_Bnd_Box2d.def("Transformed", (Bnd_Box2d (Bnd_Box2d::*)(const gp_Trsf2d &) const) &Bnd_Box2d::Transformed, "Returns a bounding box which is the result of applying the transformation T to this bounding box. Warning Applying a geometric transformation (for example, a rotation) to a bounding box generally increases its dimensions. This is not optimal for algorithms which use it.", py::arg("T"));
cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const Bnd_Box2d &)) &Bnd_Box2d::Add, "Adds the 2d box <Other> to <me>.", py::arg("Other"));
cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const gp_Pnt2d &)) &Bnd_Box2d::Add, "Adds the 2d point.", py::arg("thePnt"));
cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const gp_Pnt2d &, const gp_Dir2d &)) &Bnd_Box2d::Add, "Extends bounding box from thePnt in the direction theDir.", py::arg("thePnt"), py::arg("theDir"));
cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const gp_Dir2d &)) &Bnd_Box2d::Add, "Extends the Box in the given Direction, i.e. adds a half-line. The box may become infinite in 1 or 2 directions.", py::arg("D"));
cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const gp_Pnt2d &) const) &Bnd_Box2d::IsOut, "Returns True if the 2d pnt <P> is out <me>.", py::arg("P"));
cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const Bnd_Box2d &) const) &Bnd_Box2d::IsOut, "Returns True if <Box2d> is out <me>.", py::arg("Other"));
cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const Bnd_Box2d &, const gp_Trsf2d &) const) &Bnd_Box2d::IsOut, "Returns True if transformed <Box2d> is out <me>.", py::arg("theOther"), py::arg("theTrsf"));
cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const gp_Trsf2d &, const Bnd_Box2d &, const gp_Trsf2d &) const) &Bnd_Box2d::IsOut, "Compares a transformed bounding with a transformed bounding. The default implementation is to make a copy of <me> and <Other>, to transform them and to test.", py::arg("T1"), py::arg("Other"), py::arg("T2"));
cls_Bnd_Box2d.def("Dump", (void (Bnd_Box2d::*)() const) &Bnd_Box2d::Dump, "None");
cls_Bnd_Box2d.def("SquareExtent", (Standard_Real (Bnd_Box2d::*)() const) &Bnd_Box2d::SquareExtent, "Computes the squared diagonal of me.");

// Enums

}