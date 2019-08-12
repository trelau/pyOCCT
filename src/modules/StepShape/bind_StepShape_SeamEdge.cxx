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
#include <StepShape_OrientedEdge.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Pcurve.hxx>
#include <StepShape_SeamEdge.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_SeamEdge(py::module &mod){

py::class_<StepShape_SeamEdge, opencascade::handle<StepShape_SeamEdge>, StepShape_OrientedEdge> cls_StepShape_SeamEdge(mod, "StepShape_SeamEdge", "Representation of STEP entity SeamEdge");

// Constructors
cls_StepShape_SeamEdge.def(py::init<>());

// Fields

// Methods
cls_StepShape_SeamEdge.def("Init", (void (StepShape_SeamEdge::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Edge> &, const Standard_Boolean, const opencascade::handle<StepGeom_Pcurve> &)) &StepShape_SeamEdge::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aOrientedEdge_EdgeElement"), py::arg("aOrientedEdge_Orientation"), py::arg("aPcurveReference"));
cls_StepShape_SeamEdge.def("PcurveReference", (opencascade::handle<StepGeom_Pcurve> (StepShape_SeamEdge::*)() const) &StepShape_SeamEdge::PcurveReference, "Returns field PcurveReference");
cls_StepShape_SeamEdge.def("SetPcurveReference", (void (StepShape_SeamEdge::*)(const opencascade::handle<StepGeom_Pcurve> &)) &StepShape_SeamEdge::SetPcurveReference, "Set field PcurveReference", py::arg("PcurveReference"));
cls_StepShape_SeamEdge.def_static("get_type_name_", (const char * (*)()) &StepShape_SeamEdge::get_type_name, "None");
cls_StepShape_SeamEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_SeamEdge::get_type_descriptor, "None");
cls_StepShape_SeamEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_SeamEdge::*)() const) &StepShape_SeamEdge::DynamicType, "None");

// Enums

}