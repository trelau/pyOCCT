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
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box.hxx>
#include <gp_Trsf.hxx>
#include <gp_Lin.hxx>
#include <gp_Pln.hxx>

void bind_Bnd_Box(py::module &mod){

py::class_<Bnd_Box, std::unique_ptr<Bnd_Box>> cls_Bnd_Box(mod, "Bnd_Box", "Describes a bounding box in 3D space. A bounding box is parallel to the axes of the coordinates system. If it is finite, it is defined by the three intervals: - [ Xmin,Xmax ], - [ Ymin,Ymax ], - [ Zmin,Zmax ]. A bounding box may be infinite (i.e. open) in one or more directions. It is said to be: - OpenXmin if it is infinite on the negative side of the 'X Direction'; - OpenXmax if it is infinite on the positive side of the 'X Direction'; - OpenYmin if it is infinite on the negative side of the 'Y Direction'; - OpenYmax if it is infinite on the positive side of the 'Y Direction'; - OpenZmin if it is infinite on the negative side of the 'Z Direction'; - OpenZmax if it is infinite on the positive side of the 'Z Direction'; - WholeSpace if it is infinite in all six directions. In this case, any point of the space is inside the box; - Void if it is empty. In this case, there is no point included in the box. A bounding box is defined by: - six bounds (Xmin, Xmax, Ymin, Ymax, Zmin and Zmax) which limit the bounding box if it is finite, - eight flags (OpenXmin, OpenXmax, OpenYmin, OpenYmax, OpenZmin, OpenZmax, WholeSpace and Void) which describe the bounding box if it is infinite or empty, and - a gap, which is included on both sides in any direction when consulting the finite bounds of the box.");

// Constructors
cls_Bnd_Box.def(py::init<>());

// Fields

// Methods
// cls_Bnd_Box.def_static("operator new_", (void * (*)(size_t)) &Bnd_Box::operator new, "None", py::arg("theSize"));
// cls_Bnd_Box.def_static("operator delete_", (void (*)(void *)) &Bnd_Box::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_Box.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_Box::operator new[], "None", py::arg("theSize"));
// cls_Bnd_Box.def_static("operator delete[]_", (void (*)(void *)) &Bnd_Box::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_Box.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_Box::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_Box.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_Box::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_Box.def("SetWhole", (void (Bnd_Box::*)()) &Bnd_Box::SetWhole, "Sets this bounding box so that it covers the whole of 3D space. It is infinitely long in all directions.");
cls_Bnd_Box.def("SetVoid", (void (Bnd_Box::*)()) &Bnd_Box::SetVoid, "Sets this bounding box so that it is empty. All points are outside a void box.");
cls_Bnd_Box.def("Set", (void (Bnd_Box::*)(const gp_Pnt &)) &Bnd_Box::Set, "Sets this bounding box so that it bounds - the point P. This involves first setting this bounding box to be void and then adding the point P.", py::arg("P"));
cls_Bnd_Box.def("Set", (void (Bnd_Box::*)(const gp_Pnt &, const gp_Dir &)) &Bnd_Box::Set, "Sets this bounding box so that it bounds the half-line defined by point P and direction D, i.e. all points M defined by M=P+u*D, where u is greater than or equal to 0, are inside the bounding volume. This involves first setting this box to be void and then adding the half-line.", py::arg("P"), py::arg("D"));
cls_Bnd_Box.def("Update", (void (Bnd_Box::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Bnd_Box::Update, "Enlarges this bounding box, if required, so that it contains at least: - interval [ aXmin,aXmax ] in the 'X Direction', - interval [ aYmin,aYmax ] in the 'Y Direction', - interval [ aZmin,aZmax ] in the 'Z Direction';", py::arg("aXmin"), py::arg("aYmin"), py::arg("aZmin"), py::arg("aXmax"), py::arg("aYmax"), py::arg("aZmax"));
cls_Bnd_Box.def("Update", (void (Bnd_Box::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Bnd_Box::Update, "Adds a point of coordinates (X,Y,Z) to this bounding box.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_Bnd_Box.def("GetGap", (Standard_Real (Bnd_Box::*)() const) &Bnd_Box::GetGap, "Returns the gap of this bounding box.");
cls_Bnd_Box.def("SetGap", (void (Bnd_Box::*)(const Standard_Real)) &Bnd_Box::SetGap, "Set the gap of this bounding box to abs(Tol).", py::arg("Tol"));
cls_Bnd_Box.def("Enlarge", (void (Bnd_Box::*)(const Standard_Real)) &Bnd_Box::Enlarge, "Enlarges the box with a tolerance value. (minvalues-Abs(<tol>) and maxvalues+Abs(<tol>)) This means that the minimum values of its X, Y and Z intervals of definition, when they are finite, are reduced by the absolute value of Tol, while the maximum values are increased by the same amount.", py::arg("Tol"));
cls_Bnd_Box.def("Get", [](Bnd_Box &self, Standard_Real & theXmin, Standard_Real & theYmin, Standard_Real & theZmin, Standard_Real & theXmax, Standard_Real & theYmax, Standard_Real & theZmax){ self.Get(theXmin, theYmin, theZmin, theXmax, theYmax, theZmax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(theXmin, theYmin, theZmin, theXmax, theYmax, theZmax); }, "Returns the bounds of this bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). Standard_ConstructionError exception will be thrown if the box is void. if IsVoid()", py::arg("theXmin"), py::arg("theYmin"), py::arg("theZmin"), py::arg("theXmax"), py::arg("theYmax"), py::arg("theZmax"));
cls_Bnd_Box.def("CornerMin", (gp_Pnt (Bnd_Box::*)() const) &Bnd_Box::CornerMin, "Returns the lower corner of this bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). Standard_ConstructionError exception will be thrown if the box is void. if IsVoid()");
cls_Bnd_Box.def("CornerMax", (gp_Pnt (Bnd_Box::*)() const) &Bnd_Box::CornerMax, "Returns the upper corner of this bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). Standard_ConstructionError exception will be thrown if the box is void. if IsVoid()");
cls_Bnd_Box.def("OpenXmin", (void (Bnd_Box::*)()) &Bnd_Box::OpenXmin, "The Box will be infinitely long in the Xmin direction.");
cls_Bnd_Box.def("OpenXmax", (void (Bnd_Box::*)()) &Bnd_Box::OpenXmax, "The Box will be infinitely long in the Xmax direction.");
cls_Bnd_Box.def("OpenYmin", (void (Bnd_Box::*)()) &Bnd_Box::OpenYmin, "The Box will be infinitely long in the Ymin direction.");
cls_Bnd_Box.def("OpenYmax", (void (Bnd_Box::*)()) &Bnd_Box::OpenYmax, "The Box will be infinitely long in the Ymax direction.");
cls_Bnd_Box.def("OpenZmin", (void (Bnd_Box::*)()) &Bnd_Box::OpenZmin, "The Box will be infinitely long in the Zmin direction.");
cls_Bnd_Box.def("OpenZmax", (void (Bnd_Box::*)()) &Bnd_Box::OpenZmax, "The Box will be infinitely long in the Zmax direction.");
cls_Bnd_Box.def("IsOpenXmin", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenXmin, "Returns true if this bounding box is open in the Xmin direction.");
cls_Bnd_Box.def("IsOpenXmax", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenXmax, "Returns true if this bounding box is open in the Xmax direction.");
cls_Bnd_Box.def("IsOpenYmin", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenYmin, "Returns true if this bounding box is open in the Ymix direction.");
cls_Bnd_Box.def("IsOpenYmax", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenYmax, "Returns true if this bounding box is open in the Ymax direction.");
cls_Bnd_Box.def("IsOpenZmin", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenZmin, "Returns true if this bounding box is open in the Zmin direction.");
cls_Bnd_Box.def("IsOpenZmax", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenZmax, "Returns true if this bounding box is open in the Zmax direction.");
cls_Bnd_Box.def("IsWhole", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsWhole, "Returns true if this bounding box is infinite in all 6 directions (WholeSpace flag).");
cls_Bnd_Box.def("IsVoid", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsVoid, "Returns true if this bounding box is empty (Void flag).");
cls_Bnd_Box.def("IsXThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const) &Bnd_Box::IsXThin, "true if xmax-xmin < tol.", py::arg("tol"));
cls_Bnd_Box.def("IsYThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const) &Bnd_Box::IsYThin, "true if ymax-ymin < tol.", py::arg("tol"));
cls_Bnd_Box.def("IsZThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const) &Bnd_Box::IsZThin, "true if zmax-zmin < tol.", py::arg("tol"));
cls_Bnd_Box.def("IsThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const) &Bnd_Box::IsThin, "Returns true if IsXThin, IsYThin and IsZThin are all true, i.e. if the box is thin in all three dimensions.", py::arg("tol"));
cls_Bnd_Box.def("Transformed", (Bnd_Box (Bnd_Box::*)(const gp_Trsf &) const) &Bnd_Box::Transformed, "Returns a bounding box which is the result of applying the transformation T to this bounding box. Warning Applying a geometric transformation (for example, a rotation) to a bounding box generally increases its dimensions. This is not optimal for algorithms which use it.", py::arg("T"));
cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const Bnd_Box &)) &Bnd_Box::Add, "Adds the box <Other> to <me>.", py::arg("Other"));
cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const gp_Pnt &)) &Bnd_Box::Add, "Adds a Pnt to the box.", py::arg("P"));
cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const gp_Pnt &, const gp_Dir &)) &Bnd_Box::Add, "Extends <me> from the Pnt <P> in the direction <D>.", py::arg("P"), py::arg("D"));
cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const gp_Dir &)) &Bnd_Box::Add, "Extends the Box in the given Direction, i.e. adds an half-line. The box may become infinite in 1,2 or 3 directions.", py::arg("D"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Pnt &) const) &Bnd_Box::IsOut, "Returns True if the Pnt is out the box.", py::arg("P"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Lin &) const) &Bnd_Box::IsOut, "Returns False if the line intersects the box.", py::arg("L"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Pln &) const) &Bnd_Box::IsOut, "Returns False if the plane intersects the box.", py::arg("P"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const Bnd_Box &) const) &Bnd_Box::IsOut, "Returns False if the <Box> intersects or is inside <me>.", py::arg("Other"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const Bnd_Box &, const gp_Trsf &) const) &Bnd_Box::IsOut, "Returns False if the transformed <Box> intersects or is inside <me>.", py::arg("Other"), py::arg("T"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Trsf &, const Bnd_Box &, const gp_Trsf &) const) &Bnd_Box::IsOut, "Returns False if the transformed <Box> intersects or is inside the transformed box <me>.", py::arg("T1"), py::arg("Other"), py::arg("T2"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Pnt &, const gp_Pnt &, const gp_Dir &) const) &Bnd_Box::IsOut, "Returns False if the flat band lying between two parallel lines represented by their reference points <P1>, <P2> and direction <D> intersects the box.", py::arg("P1"), py::arg("P2"), py::arg("D"));
cls_Bnd_Box.def("Distance", (Standard_Real (Bnd_Box::*)(const Bnd_Box &) const) &Bnd_Box::Distance, "Computes the minimum distance between two boxes.", py::arg("Other"));
cls_Bnd_Box.def("Dump", (void (Bnd_Box::*)() const) &Bnd_Box::Dump, "None");
cls_Bnd_Box.def("SquareExtent", (Standard_Real (Bnd_Box::*)() const) &Bnd_Box::SquareExtent, "Computes the squared diagonal of me.");

// Enums

}