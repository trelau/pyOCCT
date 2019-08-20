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
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_FaceDivide.hxx>
#include <Message_Msg.hxx>
#include <ShapeUpgrade_ShapeConvertToBezier.hxx>

void bind_ShapeUpgrade_ShapeConvertToBezier(py::module &mod){

py::class_<ShapeUpgrade_ShapeConvertToBezier, std::unique_ptr<ShapeUpgrade_ShapeConvertToBezier>, ShapeUpgrade_ShapeDivide> cls_ShapeUpgrade_ShapeConvertToBezier(mod, "ShapeUpgrade_ShapeConvertToBezier", "API class for performing conversion of 3D, 2D curves to bezier curves and surfaces to bezier based surfaces ( bezier surface, surface of revolution based on bezier curve, offset surface based on any previous type).");

// Constructors
cls_ShapeUpgrade_ShapeConvertToBezier.def(py::init<>());
cls_ShapeUpgrade_ShapeConvertToBezier.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_ShapeUpgrade_ShapeConvertToBezier.def_static("operator new_", (void * (*)(size_t)) &ShapeUpgrade_ShapeConvertToBezier::operator new, "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShapeConvertToBezier.def_static("operator delete_", (void (*)(void *)) &ShapeUpgrade_ShapeConvertToBezier::operator delete, "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeConvertToBezier.def_static("operator new[]_", (void * (*)(size_t)) &ShapeUpgrade_ShapeConvertToBezier::operator new[], "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShapeConvertToBezier.def_static("operator delete[]_", (void (*)(void *)) &ShapeUpgrade_ShapeConvertToBezier::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeConvertToBezier.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeUpgrade_ShapeConvertToBezier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeConvertToBezier.def_static("operator delete_", (void (*)(void *, void *)) &ShapeUpgrade_ShapeConvertToBezier::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeUpgrade_ShapeConvertToBezier.def("Set2dConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Set2dConversion, "Sets mode for conversion 2D curves to bezier.", py::arg("mode"));
cls_ShapeUpgrade_ShapeConvertToBezier.def("Get2dConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const) &ShapeUpgrade_ShapeConvertToBezier::Get2dConversion, "Returns the 2D conversion mode.");
cls_ShapeUpgrade_ShapeConvertToBezier.def("Set3dConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Set3dConversion, "Sets mode for conversion 3d curves to bezier.", py::arg("mode"));
cls_ShapeUpgrade_ShapeConvertToBezier.def("Get3dConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const) &ShapeUpgrade_ShapeConvertToBezier::Get3dConversion, "Returns the 3D conversion mode.");
cls_ShapeUpgrade_ShapeConvertToBezier.def("SetSurfaceConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::SetSurfaceConversion, "Sets mode for conversion surfaces curves to bezier basis.", py::arg("mode"));
cls_ShapeUpgrade_ShapeConvertToBezier.def("GetSurfaceConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const) &ShapeUpgrade_ShapeConvertToBezier::GetSurfaceConversion, "Returns the surface conversion mode.");
cls_ShapeUpgrade_ShapeConvertToBezier.def("Set3dLineConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Set3dLineConversion, "Sets mode for conversion Geom_Line to bezier.", py::arg("mode"));
cls_ShapeUpgrade_ShapeConvertToBezier.def("Get3dLineConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const) &ShapeUpgrade_ShapeConvertToBezier::Get3dLineConversion, "Returns the Geom_Line conversion mode.");
cls_ShapeUpgrade_ShapeConvertToBezier.def("Set3dCircleConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Set3dCircleConversion, "Sets mode for conversion Geom_Circle to bezier.", py::arg("mode"));
cls_ShapeUpgrade_ShapeConvertToBezier.def("Get3dCircleConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const) &ShapeUpgrade_ShapeConvertToBezier::Get3dCircleConversion, "Returns the Geom_Circle conversion mode.");
cls_ShapeUpgrade_ShapeConvertToBezier.def("Set3dConicConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Set3dConicConversion, "Sets mode for conversion Geom_Conic to bezier.", py::arg("mode"));
cls_ShapeUpgrade_ShapeConvertToBezier.def("Get3dConicConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const) &ShapeUpgrade_ShapeConvertToBezier::Get3dConicConversion, "Returns the Geom_Conic conversion mode.");
cls_ShapeUpgrade_ShapeConvertToBezier.def("SetPlaneMode", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::SetPlaneMode, "Sets mode for conversion Geom_Plane to Bezier", py::arg("mode"));
cls_ShapeUpgrade_ShapeConvertToBezier.def("GetPlaneMode", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const) &ShapeUpgrade_ShapeConvertToBezier::GetPlaneMode, "Returns the Geom_Pline conversion mode.");
cls_ShapeUpgrade_ShapeConvertToBezier.def("SetRevolutionMode", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::SetRevolutionMode, "Sets mode for conversion Geom_SurfaceOfRevolution to Bezier", py::arg("mode"));
cls_ShapeUpgrade_ShapeConvertToBezier.def("GetRevolutionMode", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const) &ShapeUpgrade_ShapeConvertToBezier::GetRevolutionMode, "Returns the Geom_SurfaceOfRevolution conversion mode.");
cls_ShapeUpgrade_ShapeConvertToBezier.def("SetExtrusionMode", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::SetExtrusionMode, "Sets mode for conversion Geom_SurfaceOfLinearExtrusion to Bezier", py::arg("mode"));
cls_ShapeUpgrade_ShapeConvertToBezier.def("GetExtrusionMode", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const) &ShapeUpgrade_ShapeConvertToBezier::GetExtrusionMode, "Returns the Geom_SurfaceOfLinearExtrusion conversion mode.");
cls_ShapeUpgrade_ShapeConvertToBezier.def("SetBSplineMode", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::SetBSplineMode, "Sets mode for conversion Geom_BSplineSurface to Bezier", py::arg("mode"));
cls_ShapeUpgrade_ShapeConvertToBezier.def("GetBSplineMode", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const) &ShapeUpgrade_ShapeConvertToBezier::GetBSplineMode, "Returns the Geom_BSplineSurface conversion mode.");
cls_ShapeUpgrade_ShapeConvertToBezier.def("Perform", [](ShapeUpgrade_ShapeConvertToBezier &self) -> Standard_Boolean { return self.Perform(); });
cls_ShapeUpgrade_ShapeConvertToBezier.def("Perform", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Perform, "Performs converting and computes the resulting shape", py::arg("newContext"));

// Enums

}