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
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <gp_Dir.hxx>
#include <gp_Pln.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <LocOpe_SplitDrafts.hxx>

void bind_LocOpe_SplitDrafts(py::module &mod){

py::class_<LocOpe_SplitDrafts, std::unique_ptr<LocOpe_SplitDrafts>> cls_LocOpe_SplitDrafts(mod, "LocOpe_SplitDrafts", "This class provides a tool to realize the following operations on a shape : - split a face of the shape with a wire, - put draft angle on both side of the wire. For each side, the draft angle may be different.");

// Constructors
cls_LocOpe_SplitDrafts.def(py::init<>());
cls_LocOpe_SplitDrafts.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_LocOpe_SplitDrafts.def_static("operator new_", (void * (*)(size_t)) &LocOpe_SplitDrafts::operator new, "None", py::arg("theSize"));
// cls_LocOpe_SplitDrafts.def_static("operator delete_", (void (*)(void *)) &LocOpe_SplitDrafts::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_SplitDrafts.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_SplitDrafts::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_SplitDrafts.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_SplitDrafts::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_SplitDrafts.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_SplitDrafts::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_SplitDrafts.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_SplitDrafts::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_SplitDrafts.def("Init", (void (LocOpe_SplitDrafts::*)(const TopoDS_Shape &)) &LocOpe_SplitDrafts::Init, "Initializes the algoritm with the shape <S>.", py::arg("S"));
cls_LocOpe_SplitDrafts.def("Perform", [](LocOpe_SplitDrafts &self, const TopoDS_Face & a0, const TopoDS_Wire & a1, const gp_Dir & a2, const gp_Pln & a3, const Standard_Real a4, const gp_Dir & a5, const gp_Pln & a6, const Standard_Real a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_LocOpe_SplitDrafts.def("Perform", [](LocOpe_SplitDrafts &self, const TopoDS_Face & a0, const TopoDS_Wire & a1, const gp_Dir & a2, const gp_Pln & a3, const Standard_Real a4, const gp_Dir & a5, const gp_Pln & a6, const Standard_Real a7, const Standard_Boolean a8) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_LocOpe_SplitDrafts.def("Perform", (void (LocOpe_SplitDrafts::*)(const TopoDS_Face &, const TopoDS_Wire &, const gp_Dir &, const gp_Pln &, const Standard_Real, const gp_Dir &, const gp_Pln &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &LocOpe_SplitDrafts::Perform, "Splits the face <F> of the former given shape with the wire <W>. The wire is assumed to lie on the face. Puts a draft angle on both parts of the wire. <Extractg>, <Nplg>, <Angleg> define the arguments for the left part of the wire. <Extractd>, <Npld>, <Angled> define the arguments for the right part of the wire. The draft angle is measured with the direction <Extract>. <Npl> defines the neutral plane (points belonging to the neutral plane are not modified). <Angle> is the value of the draft angle. If <ModifyLeft> is set to <Standard_False>, no draft angle is applied to the left part of the wire. If <ModifyRight> is set to <Standard_False>,no draft angle is applied to the right part of the wire.", py::arg("F"), py::arg("W"), py::arg("Extractg"), py::arg("NPlg"), py::arg("Angleg"), py::arg("Extractd"), py::arg("NPld"), py::arg("Angled"), py::arg("ModifyLeft"), py::arg("ModifyRight"));
cls_LocOpe_SplitDrafts.def("Perform", (void (LocOpe_SplitDrafts::*)(const TopoDS_Face &, const TopoDS_Wire &, const gp_Dir &, const gp_Pln &, const Standard_Real)) &LocOpe_SplitDrafts::Perform, "Splits the face <F> of the former given shape with the wire <W>. The wire is assumed to lie on the face. Puts a draft angle on the left part of the wire. The draft angle is measured with the direction <Extract>. <Npl> defines the neutral plane (points belonging to the neutral plane are not modified). <Angle> is the value of the draft angle.", py::arg("F"), py::arg("W"), py::arg("Extract"), py::arg("NPl"), py::arg("Angle"));
cls_LocOpe_SplitDrafts.def("IsDone", (Standard_Boolean (LocOpe_SplitDrafts::*)() const) &LocOpe_SplitDrafts::IsDone, "Returns <Standard_True> if the modification has been succesfully performed.");
cls_LocOpe_SplitDrafts.def("OriginalShape", (const TopoDS_Shape & (LocOpe_SplitDrafts::*)() const) &LocOpe_SplitDrafts::OriginalShape, "None");
cls_LocOpe_SplitDrafts.def("Shape", (const TopoDS_Shape & (LocOpe_SplitDrafts::*)() const) &LocOpe_SplitDrafts::Shape, "Returns the modified shape.");
cls_LocOpe_SplitDrafts.def("ShapesFromShape", (const TopTools_ListOfShape & (LocOpe_SplitDrafts::*)(const TopoDS_Shape &) const) &LocOpe_SplitDrafts::ShapesFromShape, "Manages the descendant shapes.", py::arg("S"));

// Enums

}