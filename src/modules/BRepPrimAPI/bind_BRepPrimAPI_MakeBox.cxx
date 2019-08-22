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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax2.hxx>
#include <BRepPrim_Wedge.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Face.hxx>
#include <BRepPrimAPI_MakeBox.hxx>

void bind_BRepPrimAPI_MakeBox(py::module &mod){

py::class_<BRepPrimAPI_MakeBox, BRepBuilderAPI_MakeShape> cls_BRepPrimAPI_MakeBox(mod, "BRepPrimAPI_MakeBox", "Describes functions to build parallelepiped boxes. A MakeBox object provides a framework for: - defining the construction of a box, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepPrimAPI_MakeBox.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("dx"), py::arg("dy"), py::arg("dz"));
cls_BRepPrimAPI_MakeBox.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("dx"), py::arg("dy"), py::arg("dz"));
cls_BRepPrimAPI_MakeBox.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_BRepPrimAPI_MakeBox.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"));

// Fields

// Methods
// cls_BRepPrimAPI_MakeBox.def_static("operator new_", (void * (*)(size_t)) &BRepPrimAPI_MakeBox::operator new, "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeBox.def_static("operator delete_", (void (*)(void *)) &BRepPrimAPI_MakeBox::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeBox.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrimAPI_MakeBox::operator new[], "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeBox.def_static("operator delete[]_", (void (*)(void *)) &BRepPrimAPI_MakeBox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeBox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrimAPI_MakeBox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrimAPI_MakeBox.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrimAPI_MakeBox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrimAPI_MakeBox.def("Wedge", (BRepPrim_Wedge & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::Wedge, "Returns the internal algorithm.");
cls_BRepPrimAPI_MakeBox.def("Build", (void (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::Build, "Stores the solid in myShape.");
cls_BRepPrimAPI_MakeBox.def("Shell", (const TopoDS_Shell & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::Shell, "Returns the constructed box as a shell.");
cls_BRepPrimAPI_MakeBox.def("Solid", (const TopoDS_Solid & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::Solid, "Returns the constructed box as a solid.");
cls_BRepPrimAPI_MakeBox.def("BottomFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::BottomFace, "Returns ZMin face");
cls_BRepPrimAPI_MakeBox.def("BackFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::BackFace, "Returns XMin face");
cls_BRepPrimAPI_MakeBox.def("FrontFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::FrontFace, "Returns XMax face");
cls_BRepPrimAPI_MakeBox.def("LeftFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::LeftFace, "Returns YMin face");
cls_BRepPrimAPI_MakeBox.def("RightFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::RightFace, "Returns YMax face");
cls_BRepPrimAPI_MakeBox.def("TopFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::TopFace, "Returns ZMax face");

// Enums

}