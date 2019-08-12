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
#include <StepToTopoDS_Root.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <StepGeom_CartesianTransformationOperator3d.hxx>
#include <gp_Trsf.hxx>
#include <TopoDS_Shape.hxx>
#include <StepRepr_MappedItem.hxx>
#include <Transfer_TransientProcess.hxx>
#include <StepToTopoDS_MakeTransformed.hxx>

void bind_StepToTopoDS_MakeTransformed(py::module &mod){

py::class_<StepToTopoDS_MakeTransformed, std::unique_ptr<StepToTopoDS_MakeTransformed, Deleter<StepToTopoDS_MakeTransformed>>, StepToTopoDS_Root> cls_StepToTopoDS_MakeTransformed(mod, "StepToTopoDS_MakeTransformed", "Produces instances by Transformation of a basic item");

// Constructors
cls_StepToTopoDS_MakeTransformed.def(py::init<>());

// Fields

// Methods
// cls_StepToTopoDS_MakeTransformed.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_MakeTransformed::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_MakeTransformed.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_MakeTransformed::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_MakeTransformed.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_MakeTransformed::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_MakeTransformed.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_MakeTransformed::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_MakeTransformed.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_MakeTransformed::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_MakeTransformed.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_MakeTransformed::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_MakeTransformed.def("Compute", (Standard_Boolean (StepToTopoDS_MakeTransformed::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepToTopoDS_MakeTransformed::Compute, "Computes a transformation to pass from an Origin placement to a Target placement. Returns True when done If not done, the transformation will by Identity", py::arg("Origin"), py::arg("Target"));
cls_StepToTopoDS_MakeTransformed.def("Compute", (Standard_Boolean (StepToTopoDS_MakeTransformed::*)(const opencascade::handle<StepGeom_CartesianTransformationOperator3d> &)) &StepToTopoDS_MakeTransformed::Compute, "Computes a transformation defined by an operator 3D", py::arg("Operator"));
cls_StepToTopoDS_MakeTransformed.def("Transformation", (const gp_Trsf & (StepToTopoDS_MakeTransformed::*)() const) &StepToTopoDS_MakeTransformed::Transformation, "Returns the computed transformation (Identity if not yet or if failed)");
cls_StepToTopoDS_MakeTransformed.def("Transform", (Standard_Boolean (StepToTopoDS_MakeTransformed::*)(TopoDS_Shape &) const) &StepToTopoDS_MakeTransformed::Transform, "Applies the computed transformation to a shape Returns False if the transformation is Identity", py::arg("shape"));
cls_StepToTopoDS_MakeTransformed.def("TranslateMappedItem", (TopoDS_Shape (StepToTopoDS_MakeTransformed::*)(const opencascade::handle<StepRepr_MappedItem> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_MakeTransformed::TranslateMappedItem, "Translates a MappedItem. More precisely A MappedItem has a MappingSource and a MappingTarget MappingSource has a MappedRepresentation and a MappingOrigin MappedRepresentation is the basic item to be instanced MappingOrigin is the starting placement MappingTarget is the final placement", py::arg("mapit"), py::arg("TP"));

// Enums

}