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
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepFill_TransitionStyle.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Shell.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Bnd_Box.hxx>
#include <BRepFill_DraftLaw.hxx>
#include <BRepFill_SectionLaw.hxx>
#include <TopTools_HArray2OfShape.hxx>
#include <TopoDS_Wire.hxx>
#include <GeomAbs_Shape.hxx>
#include <BRepFill_Draft.hxx>

void bind_BRepFill_Draft(py::module &mod){

py::class_<BRepFill_Draft, std::unique_ptr<BRepFill_Draft, Deleter<BRepFill_Draft>>> cls_BRepFill_Draft(mod, "BRepFill_Draft", "None");

// Constructors
cls_BRepFill_Draft.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Real>(), py::arg("Shape"), py::arg("Dir"), py::arg("Angle"));

// Fields

// Methods
// cls_BRepFill_Draft.def_static("operator new_", (void * (*)(size_t)) &BRepFill_Draft::operator new, "None", py::arg("theSize"));
// cls_BRepFill_Draft.def_static("operator delete_", (void (*)(void *)) &BRepFill_Draft::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_Draft.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_Draft::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_Draft.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_Draft::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_Draft.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_Draft::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_Draft.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_Draft::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_Draft.def("SetOptions", [](BRepFill_Draft &self) -> void { return self.SetOptions(); });
cls_BRepFill_Draft.def("SetOptions", [](BRepFill_Draft &self, const BRepFill_TransitionStyle a0) -> void { return self.SetOptions(a0); });
cls_BRepFill_Draft.def("SetOptions", [](BRepFill_Draft &self, const BRepFill_TransitionStyle a0, const Standard_Real a1) -> void { return self.SetOptions(a0, a1); });
cls_BRepFill_Draft.def("SetOptions", (void (BRepFill_Draft::*)(const BRepFill_TransitionStyle, const Standard_Real, const Standard_Real)) &BRepFill_Draft::SetOptions, "None", py::arg("Style"), py::arg("AngleMin"), py::arg("AngleMax"));
cls_BRepFill_Draft.def("SetDraft", [](BRepFill_Draft &self) -> void { return self.SetDraft(); });
cls_BRepFill_Draft.def("SetDraft", (void (BRepFill_Draft::*)(const Standard_Boolean)) &BRepFill_Draft::SetDraft, "None", py::arg("IsInternal"));
cls_BRepFill_Draft.def("Perform", (void (BRepFill_Draft::*)(const Standard_Real)) &BRepFill_Draft::Perform, "None", py::arg("LengthMax"));
cls_BRepFill_Draft.def("Perform", [](BRepFill_Draft &self, const opencascade::handle<Geom_Surface> & a0) -> void { return self.Perform(a0); });
cls_BRepFill_Draft.def("Perform", (void (BRepFill_Draft::*)(const opencascade::handle<Geom_Surface> &, const Standard_Boolean)) &BRepFill_Draft::Perform, "None", py::arg("Surface"), py::arg("KeepInsideSurface"));
cls_BRepFill_Draft.def("Perform", [](BRepFill_Draft &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); });
cls_BRepFill_Draft.def("Perform", (void (BRepFill_Draft::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepFill_Draft::Perform, "None", py::arg("StopShape"), py::arg("KeepOutSide"));
cls_BRepFill_Draft.def("IsDone", (Standard_Boolean (BRepFill_Draft::*)() const) &BRepFill_Draft::IsDone, "None");
cls_BRepFill_Draft.def("Shell", (TopoDS_Shell (BRepFill_Draft::*)() const) &BRepFill_Draft::Shell, "Returns the draft surface To have the complete shape you have to use the Shape() methode.");
cls_BRepFill_Draft.def("Generated", (const TopTools_ListOfShape & (BRepFill_Draft::*)(const TopoDS_Shape &)) &BRepFill_Draft::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepFill_Draft.def("Shape", (TopoDS_Shape (BRepFill_Draft::*)() const) &BRepFill_Draft::Shape, "None");

// Enums

}