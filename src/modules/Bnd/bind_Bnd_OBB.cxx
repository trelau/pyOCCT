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
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_XYZ.hxx>
#include <Bnd_OBB.hxx>

void bind_Bnd_OBB(py::module &mod){

py::class_<Bnd_OBB, std::unique_ptr<Bnd_OBB, Deleter<Bnd_OBB>>> cls_Bnd_OBB(mod, "Bnd_OBB", "The class describes the Oriented Bounding Box (OBB), much tighter enclosing volume for the shape than the Axis Aligned Bounding Box (AABB). The OBB is defined by a center of the box, the axes and the halves of its three dimensions. The OBB can be used more effectively than AABB as a rejection mechanism for non-interfering objects.");

// Constructors
cls_Bnd_OBB.def(py::init<>());
cls_Bnd_OBB.def(py::init<const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Dir &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theCenter"), py::arg("theXDirection"), py::arg("theYDirection"), py::arg("theZDirection"), py::arg("theHXSize"), py::arg("theHYSize"), py::arg("theHZSize"));
cls_Bnd_OBB.def(py::init<const Bnd_Box &>(), py::arg("theBox"));

// Fields

// Methods
// cls_Bnd_OBB.def_static("operator new_", (void * (*)(size_t)) &Bnd_OBB::operator new, "None", py::arg("theSize"));
// cls_Bnd_OBB.def_static("operator delete_", (void (*)(void *)) &Bnd_OBB::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_OBB.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_OBB::operator new[], "None", py::arg("theSize"));
// cls_Bnd_OBB.def_static("operator delete[]_", (void (*)(void *)) &Bnd_OBB::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_OBB.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_OBB::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_OBB.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_OBB::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_OBB.def("ReBuild", [](Bnd_OBB &self, const TColgp_Array1OfPnt & a0) -> void { return self.ReBuild(a0); });
cls_Bnd_OBB.def("ReBuild", (void (Bnd_OBB::*)(const TColgp_Array1OfPnt &, const TColStd_Array1OfReal *)) &Bnd_OBB::ReBuild, "Created new OBB covering every point in theListOfPoints. Tolerance of every such point is set by *theListOfTolerances array. If this array is not void (not null-pointer) then the resulted Bnd_OBB will be enlarged using tolerances of points lying on the box surface.", py::arg("theListOfPoints"), py::arg("theListOfTolerances"));
cls_Bnd_OBB.def("SetCenter", (void (Bnd_OBB::*)(const gp_Pnt &)) &Bnd_OBB::SetCenter, "Sets the center of OBB", py::arg("theCenter"));
cls_Bnd_OBB.def("SetXComponent", (void (Bnd_OBB::*)(const gp_Dir &, const Standard_Real)) &Bnd_OBB::SetXComponent, "Sets the X component of OBB - direction and size", py::arg("theXDirection"), py::arg("theHXSize"));
cls_Bnd_OBB.def("SetYComponent", (void (Bnd_OBB::*)(const gp_Dir &, const Standard_Real)) &Bnd_OBB::SetYComponent, "Sets the Y component of OBB - direction and size", py::arg("theYDirection"), py::arg("theHYSize"));
cls_Bnd_OBB.def("SetZComponent", (void (Bnd_OBB::*)(const gp_Dir &, const Standard_Real)) &Bnd_OBB::SetZComponent, "Sets the Z component of OBB - direction and size", py::arg("theZDirection"), py::arg("theHZSize"));
cls_Bnd_OBB.def("Center", (const gp_XYZ & (Bnd_OBB::*)() const) &Bnd_OBB::Center, "Returns the center of OBB");
cls_Bnd_OBB.def("XDirection", (const gp_XYZ & (Bnd_OBB::*)() const) &Bnd_OBB::XDirection, "Returns the X Direction of OBB");
cls_Bnd_OBB.def("YDirection", (const gp_XYZ & (Bnd_OBB::*)() const) &Bnd_OBB::YDirection, "Returns the Y Direction of OBB");
cls_Bnd_OBB.def("ZDirection", (const gp_XYZ & (Bnd_OBB::*)() const) &Bnd_OBB::ZDirection, "Returns the Z Direction of OBB");
cls_Bnd_OBB.def("XHSize", (Standard_Real (Bnd_OBB::*)() const) &Bnd_OBB::XHSize, "Returns the X Dimension of OBB");
cls_Bnd_OBB.def("YHSize", (Standard_Real (Bnd_OBB::*)() const) &Bnd_OBB::YHSize, "Returns the Y Dimension of OBB");
cls_Bnd_OBB.def("ZHSize", (Standard_Real (Bnd_OBB::*)() const) &Bnd_OBB::ZHSize, "Returns the Z Dimension of OBB");
cls_Bnd_OBB.def("IsVoid", (Standard_Boolean (Bnd_OBB::*)() const) &Bnd_OBB::IsVoid, "Checks if the box is empty.");
cls_Bnd_OBB.def("SetVoid", (void (Bnd_OBB::*)()) &Bnd_OBB::SetVoid, "Clears this box");
cls_Bnd_OBB.def("SetAABox", (void (Bnd_OBB::*)(const Standard_Boolean &)) &Bnd_OBB::SetAABox, "Sets the flag for axes aligned box", py::arg("theFlag"));
cls_Bnd_OBB.def("IsAABox", (Standard_Boolean (Bnd_OBB::*)() const) &Bnd_OBB::IsAABox, "Returns TRUE if the box is axes aligned");
cls_Bnd_OBB.def("Enlarge", (void (Bnd_OBB::*)(const Standard_Real)) &Bnd_OBB::Enlarge, "Enlarges the box with the given value", py::arg("theGapAdd"));
// cls_Bnd_OBB.def("GetVertex", (Standard_Boolean (Bnd_OBB::*)(gp_Pnt [8]) const) &Bnd_OBB::GetVertex, "Returns the array of vertices in <this>. The local coordinate of the vertex depending on the index of the array are follow: Index == 0: (-XHSize(), -YHSize(), -ZHSize()) Index == 1: ( XHSize(), -YHSize(), -ZHSize()) Index == 2: (-XHSize(), YHSize(), -ZHSize()) Index == 3: ( XHSize(), YHSize(), -ZHSize()) Index == 4: (-XHSize(), -YHSize(), ZHSize()) Index == 5: ( XHSize(), -YHSize(), ZHSize()) Index == 6: (-XHSize(), YHSize(), ZHSize()) Index == 7: ( XHSize(), YHSize(), ZHSize()).", py::arg("theP"));
cls_Bnd_OBB.def("SquareExtent", (Standard_Real (Bnd_OBB::*)() const) &Bnd_OBB::SquareExtent, "Returns square diagonal of this box");
cls_Bnd_OBB.def("IsOut", (Standard_Boolean (Bnd_OBB::*)(const Bnd_OBB &) const) &Bnd_OBB::IsOut, "Check if the box do not interfere the other box.", py::arg("theOther"));
cls_Bnd_OBB.def("IsOut", (Standard_Boolean (Bnd_OBB::*)(const gp_Pnt &) const) &Bnd_OBB::IsOut, "Check if the point is inside of <this>.", py::arg("theP"));
cls_Bnd_OBB.def("IsCompletelyInside", (Standard_Boolean (Bnd_OBB::*)(const Bnd_OBB &) const) &Bnd_OBB::IsCompletelyInside, "Check if the theOther is completely inside *this.", py::arg("theOther"));
cls_Bnd_OBB.def("Add", (void (Bnd_OBB::*)(const Bnd_OBB &)) &Bnd_OBB::Add, "Rebuilds this in order to include all previous objects (which it was created from) and theOther.", py::arg("theOther"));
cls_Bnd_OBB.def("Add", (void (Bnd_OBB::*)(const gp_Pnt &)) &Bnd_OBB::Add, "Rebuilds this in order to include all previous objects (which it was created from) and theP.", py::arg("theP"));

// Enums

}