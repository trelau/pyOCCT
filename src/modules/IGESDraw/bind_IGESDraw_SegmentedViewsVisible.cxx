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
#include <IGESData_ViewKindEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESDraw_HArray1OfViewKindEntity.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESGraph_HArray1OfColor.hxx>
#include <IGESBasic_HArray1OfLineFontEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESGraph_Color.hxx>
#include <IGESData_LineFontEntity.hxx>
#include <IGESDraw_SegmentedViewsVisible.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_SegmentedViewsVisible(py::module &mod){

py::class_<IGESDraw_SegmentedViewsVisible, opencascade::handle<IGESDraw_SegmentedViewsVisible>, IGESData_ViewKindEntity> cls_IGESDraw_SegmentedViewsVisible(mod, "IGESDraw_SegmentedViewsVisible", "defines IGESSegmentedViewsVisible, Type <402> Form <19> in package IGESDraw");

// Constructors
cls_IGESDraw_SegmentedViewsVisible.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_SegmentedViewsVisible.def("Init", (void (IGESDraw_SegmentedViewsVisible::*)(const opencascade::handle<IGESDraw_HArray1OfViewKindEntity> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESGraph_HArray1OfColor> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfLineFontEntity> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESDraw_SegmentedViewsVisible::Init, "This method is used to set the fields of the class SegmentedViewsVisible - allViews : Pointers to View Entities - allBreakpointParameters : Parameters of breakpoints - allDisplayFlags : Display flags - allColorValues : Color Values - allColorDefinitions : Color Definitions - allLineFontValues : LineFont values - allLineFontDefinitions : LineFont Definitions - allLineWeights : Line weights raises exception if Lengths of allViews, allBreakpointParameters, allDisplayFlags, allColorValues, allColorDefinitions, allLineFontValues, allLineFontDefinitions and allLineWeights are not same.", py::arg("allViews"), py::arg("allBreakpointParameters"), py::arg("allDisplayFlags"), py::arg("allColorValues"), py::arg("allColorDefinitions"), py::arg("allLineFontValues"), py::arg("allLineFontDefinitions"), py::arg("allLineWeights"));
cls_IGESDraw_SegmentedViewsVisible.def("IsSingle", (Standard_Boolean (IGESDraw_SegmentedViewsVisible::*)() const) &IGESDraw_SegmentedViewsVisible::IsSingle, "Returns False (for a complex view)");
cls_IGESDraw_SegmentedViewsVisible.def("NbViews", (Standard_Integer (IGESDraw_SegmentedViewsVisible::*)() const) &IGESDraw_SegmentedViewsVisible::NbViews, "Returns the count of Views referenced by <me> (inherited)");
cls_IGESDraw_SegmentedViewsVisible.def("NbSegmentBlocks", (Standard_Integer (IGESDraw_SegmentedViewsVisible::*)() const) &IGESDraw_SegmentedViewsVisible::NbSegmentBlocks, "returns the number of view/segment blocks in <me> Similar to NbViews but has a more general significance");
cls_IGESDraw_SegmentedViewsVisible.def("ViewItem", (opencascade::handle<IGESData_ViewKindEntity> (IGESDraw_SegmentedViewsVisible::*)(const Standard_Integer) const) &IGESDraw_SegmentedViewsVisible::ViewItem, "returns the View entity indicated by ViewIndex raises an exception if ViewIndex <= 0 or ViewIndex > NbSegmentBlocks()", py::arg("ViewIndex"));
cls_IGESDraw_SegmentedViewsVisible.def("BreakpointParameter", (Standard_Real (IGESDraw_SegmentedViewsVisible::*)(const Standard_Integer) const) &IGESDraw_SegmentedViewsVisible::BreakpointParameter, "returns the parameter of the breakpoint indicated by BreakpointIndex raises an exception if BreakpointIndex <= 0 or BreakpointIndex > NbSegmentBlocks().", py::arg("BreakpointIndex"));
cls_IGESDraw_SegmentedViewsVisible.def("DisplayFlag", (Standard_Integer (IGESDraw_SegmentedViewsVisible::*)(const Standard_Integer) const) &IGESDraw_SegmentedViewsVisible::DisplayFlag, "returns the Display flag indicated by FlagIndex raises an exception if FlagIndex <= 0 or FlagIndex > NbSegmentBlocks().", py::arg("FlagIndex"));
cls_IGESDraw_SegmentedViewsVisible.def("IsColorDefinition", (Standard_Boolean (IGESDraw_SegmentedViewsVisible::*)(const Standard_Integer) const) &IGESDraw_SegmentedViewsVisible::IsColorDefinition, "returns True if the ColorIndex'th value of the 'theColorDefinitions' field of <me> is a pointer raises an exception if ColorIndex <= 0 or ColorIndex > NbSegmentBlocks().", py::arg("ColorIndex"));
cls_IGESDraw_SegmentedViewsVisible.def("ColorValue", (Standard_Integer (IGESDraw_SegmentedViewsVisible::*)(const Standard_Integer) const) &IGESDraw_SegmentedViewsVisible::ColorValue, "returns the Color value indicated by ColorIndex raises an exception if ColorIndex <= 0 or ColorIndex > NbSegmentBlocks().", py::arg("ColorIndex"));
cls_IGESDraw_SegmentedViewsVisible.def("ColorDefinition", (opencascade::handle<IGESGraph_Color> (IGESDraw_SegmentedViewsVisible::*)(const Standard_Integer) const) &IGESDraw_SegmentedViewsVisible::ColorDefinition, "returns the Color definition entity indicated by ColorIndex raises an exception if ColorIndex <= 0 or ColorIndex > NbSegmentBlocks().", py::arg("ColorIndex"));
cls_IGESDraw_SegmentedViewsVisible.def("IsFontDefinition", (Standard_Boolean (IGESDraw_SegmentedViewsVisible::*)(const Standard_Integer) const) &IGESDraw_SegmentedViewsVisible::IsFontDefinition, "returns True if the FontIndex'th value of the 'theLineFontDefinitions' field of <me> is a pointer raises an exception if FontIndex <= 0 or FontIndex > NbSegmentBlocks().", py::arg("FontIndex"));
cls_IGESDraw_SegmentedViewsVisible.def("LineFontValue", (Standard_Integer (IGESDraw_SegmentedViewsVisible::*)(const Standard_Integer) const) &IGESDraw_SegmentedViewsVisible::LineFontValue, "returns the LineFont value indicated by FontIndex raises an exception if FontIndex <= 0 or FontIndex > NbSegmentBlocks().", py::arg("FontIndex"));
cls_IGESDraw_SegmentedViewsVisible.def("LineFontDefinition", (opencascade::handle<IGESData_LineFontEntity> (IGESDraw_SegmentedViewsVisible::*)(const Standard_Integer) const) &IGESDraw_SegmentedViewsVisible::LineFontDefinition, "returns the LineFont definition entity indicated by FontIndex raises an exception if FontIndex <= 0 or FontIndex > NbSegmentBlocks().", py::arg("FontIndex"));
cls_IGESDraw_SegmentedViewsVisible.def("LineWeightItem", (Standard_Integer (IGESDraw_SegmentedViewsVisible::*)(const Standard_Integer) const) &IGESDraw_SegmentedViewsVisible::LineWeightItem, "returns the LineWeight value indicated by WeightIndex raises an exception if WeightIndex <= 0 or WeightIndex > NbSegmentBlocks().", py::arg("WeightIndex"));
cls_IGESDraw_SegmentedViewsVisible.def_static("get_type_name_", (const char * (*)()) &IGESDraw_SegmentedViewsVisible::get_type_name, "None");
cls_IGESDraw_SegmentedViewsVisible.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_SegmentedViewsVisible::get_type_descriptor, "None");
cls_IGESDraw_SegmentedViewsVisible.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_SegmentedViewsVisible::*)() const) &IGESDraw_SegmentedViewsVisible::DynamicType, "None");

// Enums

}