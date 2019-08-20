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
#include <ShapeUpgrade_ShapeDivide.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_FaceDivide.hxx>
#include <ShapeUpgrade_ShapeDivideContinuity.hxx>

void bind_ShapeUpgrade_ShapeDivideContinuity(py::module &mod){

py::class_<ShapeUpgrade_ShapeDivideContinuity, std::unique_ptr<ShapeUpgrade_ShapeDivideContinuity>, ShapeUpgrade_ShapeDivide> cls_ShapeUpgrade_ShapeDivideContinuity(mod, "ShapeUpgrade_ShapeDivideContinuity", "API Tool for converting shapes with C0 geometry into C1 ones");

// Constructors
cls_ShapeUpgrade_ShapeDivideContinuity.def(py::init<>());
cls_ShapeUpgrade_ShapeDivideContinuity.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_ShapeUpgrade_ShapeDivideContinuity.def_static("operator new_", (void * (*)(size_t)) &ShapeUpgrade_ShapeDivideContinuity::operator new, "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShapeDivideContinuity.def_static("operator delete_", (void (*)(void *)) &ShapeUpgrade_ShapeDivideContinuity::operator delete, "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivideContinuity.def_static("operator new[]_", (void * (*)(size_t)) &ShapeUpgrade_ShapeDivideContinuity::operator new[], "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShapeDivideContinuity.def_static("operator delete[]_", (void (*)(void *)) &ShapeUpgrade_ShapeDivideContinuity::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivideContinuity.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeUpgrade_ShapeDivideContinuity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivideContinuity.def_static("operator delete_", (void (*)(void *, void *)) &ShapeUpgrade_ShapeDivideContinuity::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeUpgrade_ShapeDivideContinuity.def("SetTolerance", (void (ShapeUpgrade_ShapeDivideContinuity::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivideContinuity::SetTolerance, "Sets tolerance.", py::arg("Tol"));
cls_ShapeUpgrade_ShapeDivideContinuity.def("SetTolerance2d", (void (ShapeUpgrade_ShapeDivideContinuity::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivideContinuity::SetTolerance2d, "Sets tolerance.", py::arg("Tol"));
cls_ShapeUpgrade_ShapeDivideContinuity.def("SetBoundaryCriterion", [](ShapeUpgrade_ShapeDivideContinuity &self) -> void { return self.SetBoundaryCriterion(); });
cls_ShapeUpgrade_ShapeDivideContinuity.def("SetBoundaryCriterion", (void (ShapeUpgrade_ShapeDivideContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_ShapeDivideContinuity::SetBoundaryCriterion, "Defines a criterion of continuity for the boundary (all the Wires)", py::arg("Criterion"));
cls_ShapeUpgrade_ShapeDivideContinuity.def("SetPCurveCriterion", [](ShapeUpgrade_ShapeDivideContinuity &self) -> void { return self.SetPCurveCriterion(); });
cls_ShapeUpgrade_ShapeDivideContinuity.def("SetPCurveCriterion", (void (ShapeUpgrade_ShapeDivideContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_ShapeDivideContinuity::SetPCurveCriterion, "Defines a criterion of continuity for the boundary (all the pcurves of Wires)", py::arg("Criterion"));
cls_ShapeUpgrade_ShapeDivideContinuity.def("SetSurfaceCriterion", [](ShapeUpgrade_ShapeDivideContinuity &self) -> void { return self.SetSurfaceCriterion(); });
cls_ShapeUpgrade_ShapeDivideContinuity.def("SetSurfaceCriterion", (void (ShapeUpgrade_ShapeDivideContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_ShapeDivideContinuity::SetSurfaceCriterion, "Defines a criterion of continuity for the boundary (all the Wires)", py::arg("Criterion"));

// Enums

}