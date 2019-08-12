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
#include <Standard_Transient.hxx>
#include <Aspect_TypeOfDeflection.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <VrmlConverter_IsoAspect.hxx>
#include <VrmlConverter_LineAspect.hxx>
#include <VrmlConverter_PointAspect.hxx>
#include <VrmlConverter_ShadingAspect.hxx>
#include <VrmlConverter_Drawer.hxx>
#include <Standard_Type.hxx>

void bind_VrmlConverter_Drawer(py::module &mod){

py::class_<VrmlConverter_Drawer, opencascade::handle<VrmlConverter_Drawer>, Standard_Transient> cls_VrmlConverter_Drawer(mod, "VrmlConverter_Drawer", "qualifies the aspect properties for the VRML conversation of a specific kind of object. This includes for example color, maximal chordial deviation, etc...");

// Constructors
cls_VrmlConverter_Drawer.def(py::init<>());

// Fields

// Methods
cls_VrmlConverter_Drawer.def("SetTypeOfDeflection", (void (VrmlConverter_Drawer::*)(const Aspect_TypeOfDeflection)) &VrmlConverter_Drawer::SetTypeOfDeflection, "by default: TOD_Relative; however, except for the shapes, the drawing will be made using the absolute deviation.", py::arg("aTypeOfDeflection"));
cls_VrmlConverter_Drawer.def("TypeOfDeflection", (Aspect_TypeOfDeflection (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::TypeOfDeflection, "None");
cls_VrmlConverter_Drawer.def("SetMaximalChordialDeviation", (void (VrmlConverter_Drawer::*)(const Standard_Real)) &VrmlConverter_Drawer::SetMaximalChordialDeviation, "Defines the maximal chordial deviation when drawing any curve; If this value is one of the obvious parameters of methods, current value from Drawer won't be used. This value is used by:", py::arg("aChordialDeviation"));
cls_VrmlConverter_Drawer.def("MaximalChordialDeviation", (Standard_Real (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::MaximalChordialDeviation, "returns the maximal chordial deviation. Default value: 0.1");
cls_VrmlConverter_Drawer.def("SetDeviationCoefficient", (void (VrmlConverter_Drawer::*)(const Standard_Real)) &VrmlConverter_Drawer::SetDeviationCoefficient, "default 0.001", py::arg("aCoefficient"));
cls_VrmlConverter_Drawer.def("DeviationCoefficient", (Standard_Real (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::DeviationCoefficient, "None");
cls_VrmlConverter_Drawer.def("SetDiscretisation", (void (VrmlConverter_Drawer::*)(const Standard_Integer)) &VrmlConverter_Drawer::SetDiscretisation, "default: 17 points. Defines the Discretisation (myNbPoints) when drawing any curve; If this value is one of the obvious parameters of methods, current value from Drawer won't be used. This value is used by:", py::arg("d"));
cls_VrmlConverter_Drawer.def("Discretisation", (Standard_Integer (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::Discretisation, "None");
cls_VrmlConverter_Drawer.def("SetMaximalParameterValue", (void (VrmlConverter_Drawer::*)(const Standard_Real)) &VrmlConverter_Drawer::SetMaximalParameterValue, "defines the maximum value allowed for the first and last parameters of an infinite curve. Default value: 500. VrmlConverter_Curve VrmlConverter_WFRestrictedFace VrmlConverter_WFShape", py::arg("Value"));
cls_VrmlConverter_Drawer.def("MaximalParameterValue", (Standard_Real (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::MaximalParameterValue, "None");
cls_VrmlConverter_Drawer.def("SetIsoOnPlane", (void (VrmlConverter_Drawer::*)(const Standard_Boolean)) &VrmlConverter_Drawer::SetIsoOnPlane, "enables the drawing of isos on planes. By default there are no isos on planes.", py::arg("OnOff"));
cls_VrmlConverter_Drawer.def("IsoOnPlane", (Standard_Boolean (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::IsoOnPlane, "returns True if the drawing of isos on planes is enabled.");
cls_VrmlConverter_Drawer.def("UIsoAspect", (opencascade::handle<VrmlConverter_IsoAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::UIsoAspect, "Defines the attributes which are used when drawing an U isoparametric curve of a face. Defines the number of U isoparametric curves to be drawn for a single face. The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetUIsoAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_IsoAspect> &)) &VrmlConverter_Drawer::SetUIsoAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("VIsoAspect", (opencascade::handle<VrmlConverter_IsoAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::VIsoAspect, "Defines the attributes which are used when drawing an V isoparametric curve of a face. Defines the number of V isoparametric curves to be drawn for a single face. The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetVIsoAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_IsoAspect> &)) &VrmlConverter_Drawer::SetVIsoAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("FreeBoundaryAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::FreeBoundaryAspect, "The default values are the same default values from Vrml package. These attributes are used by the following algorithms: VrmlConverter_WFShape VrmlConverter_WFDeflectionShape");
cls_VrmlConverter_Drawer.def("SetFreeBoundaryAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetFreeBoundaryAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("SetFreeBoundaryDraw", (void (VrmlConverter_Drawer::*)(const Standard_Boolean)) &VrmlConverter_Drawer::SetFreeBoundaryDraw, "enables the drawing the free boundaries By default the free boundaries are drawn.", py::arg("OnOff"));
cls_VrmlConverter_Drawer.def("FreeBoundaryDraw", (Standard_Boolean (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::FreeBoundaryDraw, "returns True if the drawing of the free boundaries is enabled.");
cls_VrmlConverter_Drawer.def("WireAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::WireAspect, "The default values are the same default values from Vrml package. These attributes are used by the following algorithms: VrmlConverter_WFShape VrmlConverter_WFDeflectionShape");
cls_VrmlConverter_Drawer.def("SetWireAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetWireAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("SetWireDraw", (void (VrmlConverter_Drawer::*)(const Standard_Boolean)) &VrmlConverter_Drawer::SetWireDraw, "enables the drawing the wire By default the wire are drawn.", py::arg("OnOff"));
cls_VrmlConverter_Drawer.def("WireDraw", (Standard_Boolean (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::WireDraw, "returns True if the drawing of the wire is enabled.");
cls_VrmlConverter_Drawer.def("UnFreeBoundaryAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::UnFreeBoundaryAspect, "The default values are the same default values from Vrml package. These attributes are used by the following algorithms: VrmlConverter_WFShape VrmlConverter_WFDeflectionShape");
cls_VrmlConverter_Drawer.def("SetUnFreeBoundaryAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetUnFreeBoundaryAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("SetUnFreeBoundaryDraw", (void (VrmlConverter_Drawer::*)(const Standard_Boolean)) &VrmlConverter_Drawer::SetUnFreeBoundaryDraw, "enables the drawing the unfree boundaries By default the unfree boundaries are drawn.", py::arg("OnOff"));
cls_VrmlConverter_Drawer.def("UnFreeBoundaryDraw", (Standard_Boolean (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::UnFreeBoundaryDraw, "returns True if the drawing of the unfree boundaries is enabled.");
cls_VrmlConverter_Drawer.def("LineAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::LineAspect, "The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetLineAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetLineAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("PointAspect", (opencascade::handle<VrmlConverter_PointAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::PointAspect, "None");
cls_VrmlConverter_Drawer.def("SetPointAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_PointAspect> &)) &VrmlConverter_Drawer::SetPointAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("ShadingAspect", (opencascade::handle<VrmlConverter_ShadingAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::ShadingAspect, "The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetShadingAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_ShadingAspect> &)) &VrmlConverter_Drawer::SetShadingAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("DrawHiddenLine", (Standard_Boolean (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::DrawHiddenLine, "returns Standard_True if the hidden lines are to be drawn. By default the hidden lines are not drawn.");
cls_VrmlConverter_Drawer.def("EnableDrawHiddenLine", (void (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::EnableDrawHiddenLine, "sets DrawHiddenLine = Standard_True - the hidden lines are drawn.");
cls_VrmlConverter_Drawer.def("DisableDrawHiddenLine", (void (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::DisableDrawHiddenLine, "sets DrawHiddenLine = Standard_False - the hidden lines are not drawn.");
cls_VrmlConverter_Drawer.def("HiddenLineAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::HiddenLineAspect, "returns LineAspect for the hidden lines. The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetHiddenLineAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetHiddenLineAspect, "sets LineAspect for the hidden lines.", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("SeenLineAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::SeenLineAspect, "returns LineAspect for the seen lines. The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetSeenLineAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetSeenLineAspect, "sets LineAspect for the seen lines.", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_Drawer::get_type_name, "None");
cls_VrmlConverter_Drawer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_Drawer::get_type_descriptor, "None");
cls_VrmlConverter_Drawer.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::DynamicType, "None");

// Enums

}