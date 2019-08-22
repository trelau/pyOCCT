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
#include <TopoDS_Shape.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepBuilderAPI_TransitionMode.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Shell.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepFill_Draft.hxx>
#include <BRepOffsetAPI_MakeDraft.hxx>

void bind_BRepOffsetAPI_MakeDraft(py::module &mod){

py::class_<BRepOffsetAPI_MakeDraft, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_MakeDraft(mod, "BRepOffsetAPI_MakeDraft", "Build a draft surface along a wire");

// Constructors
cls_BRepOffsetAPI_MakeDraft.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Real>(), py::arg("Shape"), py::arg("Dir"), py::arg("Angle"));

// Fields

// Methods
// cls_BRepOffsetAPI_MakeDraft.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakeDraft::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeDraft.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakeDraft::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeDraft.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakeDraft::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeDraft.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakeDraft::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeDraft.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakeDraft::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeDraft.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakeDraft::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakeDraft.def("SetOptions", [](BRepOffsetAPI_MakeDraft &self) -> void { return self.SetOptions(); });
cls_BRepOffsetAPI_MakeDraft.def("SetOptions", [](BRepOffsetAPI_MakeDraft &self, const BRepBuilderAPI_TransitionMode a0) -> void { return self.SetOptions(a0); });
cls_BRepOffsetAPI_MakeDraft.def("SetOptions", [](BRepOffsetAPI_MakeDraft &self, const BRepBuilderAPI_TransitionMode a0, const Standard_Real a1) -> void { return self.SetOptions(a0, a1); });
cls_BRepOffsetAPI_MakeDraft.def("SetOptions", (void (BRepOffsetAPI_MakeDraft::*)(const BRepBuilderAPI_TransitionMode, const Standard_Real, const Standard_Real)) &BRepOffsetAPI_MakeDraft::SetOptions, "Sets the options of this draft tool. If a transition has to be performed, it can be defined by the mode Style as RightCorner or RoundCorner, RightCorner being a corner defined by a sharp angle, and RoundCorner being a rounded corner. AngleMin is an angular tolerance used to detect whether a transition has to be performed or not. AngleMax sets the maximum value within which a RightCorner transition can be performed. AngleMin and AngleMax are expressed in radians.", py::arg("Style"), py::arg("AngleMin"), py::arg("AngleMax"));
cls_BRepOffsetAPI_MakeDraft.def("SetDraft", [](BRepOffsetAPI_MakeDraft &self) -> void { return self.SetDraft(); });
cls_BRepOffsetAPI_MakeDraft.def("SetDraft", (void (BRepOffsetAPI_MakeDraft::*)(const Standard_Boolean)) &BRepOffsetAPI_MakeDraft::SetDraft, "Sets the direction of the draft for this object. If IsInternal is true, the draft is internal to the argument Shape used in the constructor.", py::arg("IsInternal"));
cls_BRepOffsetAPI_MakeDraft.def("Perform", (void (BRepOffsetAPI_MakeDraft::*)(const Standard_Real)) &BRepOffsetAPI_MakeDraft::Perform, "Performs the draft using the length LengthMax as the maximum length for the corner edge between two draft faces.", py::arg("LengthMax"));
cls_BRepOffsetAPI_MakeDraft.def("Perform", [](BRepOffsetAPI_MakeDraft &self, const opencascade::handle<Geom_Surface> & a0) -> void { return self.Perform(a0); });
cls_BRepOffsetAPI_MakeDraft.def("Perform", (void (BRepOffsetAPI_MakeDraft::*)(const opencascade::handle<Geom_Surface> &, const Standard_Boolean)) &BRepOffsetAPI_MakeDraft::Perform, "Performs the draft up to the surface Surface. If KeepInsideSurface is true, the part of Surface inside the draft is kept in the result.", py::arg("Surface"), py::arg("KeepInsideSurface"));
cls_BRepOffsetAPI_MakeDraft.def("Perform", [](BRepOffsetAPI_MakeDraft &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); });
cls_BRepOffsetAPI_MakeDraft.def("Perform", (void (BRepOffsetAPI_MakeDraft::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepOffsetAPI_MakeDraft::Perform, "Performs the draft up to the shape StopShape. If KeepOutSide is true, the part of StopShape which is outside the Draft is kept in the result.", py::arg("StopShape"), py::arg("KeepOutSide"));
cls_BRepOffsetAPI_MakeDraft.def("Shell", (TopoDS_Shell (BRepOffsetAPI_MakeDraft::*)() const) &BRepOffsetAPI_MakeDraft::Shell, "Returns the shell resulting from performance of the draft along the wire.");
cls_BRepOffsetAPI_MakeDraft.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeDraft::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakeDraft::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));

// Enums

}