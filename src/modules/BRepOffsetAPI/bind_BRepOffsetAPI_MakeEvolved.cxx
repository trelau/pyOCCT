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
#include <TopoDS_Wire.hxx>
#include <GeomAbs_JoinType.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <BRepFill_Evolved.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepOffsetAPI_MakeEvolved.hxx>

void bind_BRepOffsetAPI_MakeEvolved(py::module &mod){

py::class_<BRepOffsetAPI_MakeEvolved, std::unique_ptr<BRepOffsetAPI_MakeEvolved, Deleter<BRepOffsetAPI_MakeEvolved>>, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_MakeEvolved(mod, "BRepOffsetAPI_MakeEvolved", "Describes functions to build evolved shapes. An evolved shape is built from a planar spine (face or wire) and a profile (wire). The evolved shape is the unlooped sweep (pipe) of the profile along the spine. Self-intersections are removed. A MakeEvolved object provides a framework for: - defining the construction of an evolved shape, - implementing the construction algorithm, and - consulting the result. Computes an Evolved by 1 - sweeping a profil along a spine. 2 - removing the self-intersections.");

// Constructors
cls_BRepOffsetAPI_MakeEvolved.def(py::init<>());
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &>(), py::arg("Spine"), py::arg("Profil"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &, const GeomAbs_JoinType>(), py::arg("Spine"), py::arg("Profil"), py::arg("Join"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profil"), py::arg("Join"), py::arg("AxeProf"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profil"), py::arg("Join"), py::arg("AxeProf"), py::arg("Solid"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profil"), py::arg("Join"), py::arg("AxeProf"), py::arg("Solid"), py::arg("ProfOnSpine"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real>(), py::arg("Spine"), py::arg("Profil"), py::arg("Join"), py::arg("AxeProf"), py::arg("Solid"), py::arg("ProfOnSpine"), py::arg("Tol"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &>(), py::arg("Spine"), py::arg("Profil"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &, const GeomAbs_JoinType>(), py::arg("Spine"), py::arg("Profil"), py::arg("Join"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profil"), py::arg("Join"), py::arg("AxeProf"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profil"), py::arg("Join"), py::arg("AxeProf"), py::arg("Solid"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profil"), py::arg("Join"), py::arg("AxeProf"), py::arg("Solid"), py::arg("ProfOnSpine"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real>(), py::arg("Spine"), py::arg("Profil"), py::arg("Join"), py::arg("AxeProf"), py::arg("Solid"), py::arg("ProfOnSpine"), py::arg("Tol"));

// Fields

// Methods
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakeEvolved::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakeEvolved::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakeEvolved::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakeEvolved::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakeEvolved::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakeEvolved::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakeEvolved.def("Evolved", (const BRepFill_Evolved & (BRepOffsetAPI_MakeEvolved::*)() const) &BRepOffsetAPI_MakeEvolved::Evolved, "None");
cls_BRepOffsetAPI_MakeEvolved.def("Build", (void (BRepOffsetAPI_MakeEvolved::*)()) &BRepOffsetAPI_MakeEvolved::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepOffsetAPI_MakeEvolved.def("GeneratedShapes", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeEvolved::*)(const TopoDS_Shape &, const TopoDS_Shape &) const) &BRepOffsetAPI_MakeEvolved::GeneratedShapes, "Returns the shapes created from a subshape <SpineShape> of the spine and a subshape <ProfShape> on the profile.", py::arg("SpineShape"), py::arg("ProfShape"));
cls_BRepOffsetAPI_MakeEvolved.def("Top", (const TopoDS_Shape & (BRepOffsetAPI_MakeEvolved::*)() const) &BRepOffsetAPI_MakeEvolved::Top, "Return the face Top if <Solid> is True in the constructor.");
cls_BRepOffsetAPI_MakeEvolved.def("Bottom", (const TopoDS_Shape & (BRepOffsetAPI_MakeEvolved::*)() const) &BRepOffsetAPI_MakeEvolved::Bottom, "Return the face Bottom if <Solid> is True in the constructor.");

// Enums

}