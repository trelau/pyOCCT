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
#include <Prs3d_BasicAspect.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_DatumAspect.hxx>
#include <Standard_Type.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Prs3d_DatumParts.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <Prs3d_TextAspect.hxx>
#include <Prs3d_PointAspect.hxx>
#include <Prs3d_ArrowAspect.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_DatumAxes.hxx>
#include <Prs3d_DatumAttribute.hxx>
#include <NCollection_DataMap.hxx>

void bind_Prs3d_DatumAspect(py::module &mod){

py::class_<Prs3d_DatumAspect, opencascade::handle<Prs3d_DatumAspect>, Prs3d_BasicAspect> cls_Prs3d_DatumAspect(mod, "Prs3d_DatumAspect", "A framework to define the display of datums.");

// Constructors
cls_Prs3d_DatumAspect.def(py::init<>());

// Fields

// Methods
cls_Prs3d_DatumAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_DatumAspect::get_type_name, "None");
cls_Prs3d_DatumAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_DatumAspect::get_type_descriptor, "None");
cls_Prs3d_DatumAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::DynamicType, "None");
cls_Prs3d_DatumAspect.def("LineAspect", (opencascade::handle<Prs3d_LineAspect> (Prs3d_DatumAspect::*)(Prs3d_DatumParts) const) &Prs3d_DatumAspect::LineAspect, "Returns the right-handed coordinate system set in SetComponent.", py::arg("thePart"));
cls_Prs3d_DatumAspect.def("ShadingAspect", (opencascade::handle<Prs3d_ShadingAspect> (Prs3d_DatumAspect::*)(Prs3d_DatumParts) const) &Prs3d_DatumAspect::ShadingAspect, "Returns the right-handed coordinate system set in SetComponent.", py::arg("thePart"));
cls_Prs3d_DatumAspect.def("TextAspect", (const opencascade::handle<Prs3d_TextAspect> & (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::TextAspect, "Returns the right-handed coordinate system set in SetComponent.");
cls_Prs3d_DatumAspect.def("PointAspect", (const opencascade::handle<Prs3d_PointAspect> & (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::PointAspect, "Returns the point aspect of origin wireframe presentation");
cls_Prs3d_DatumAspect.def("ArrowAspect", (const opencascade::handle<Prs3d_ArrowAspect> & (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::ArrowAspect, "Returns the arrow aspect of presentation");
cls_Prs3d_DatumAspect.def("FirstAxisAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::FirstAxisAspect, "Returns the attributes for display of the first axis.");
cls_Prs3d_DatumAspect.def("SecondAxisAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::SecondAxisAspect, "Returns the attributes for display of the second axis.");
cls_Prs3d_DatumAspect.def("ThirdAxisAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::ThirdAxisAspect, "Returns the attributes for display of the third axis.");
cls_Prs3d_DatumAspect.def("SetDrawFirstAndSecondAxis", (void (Prs3d_DatumAspect::*)(Standard_Boolean)) &Prs3d_DatumAspect::SetDrawFirstAndSecondAxis, "Sets the DrawFirstAndSecondAxis attributes to active.", py::arg("theToDraw"));
cls_Prs3d_DatumAspect.def("DrawFirstAndSecondAxis", (Standard_Boolean (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::DrawFirstAndSecondAxis, "Returns true if the first and second axes can be drawn.");
cls_Prs3d_DatumAspect.def("SetDrawThirdAxis", (void (Prs3d_DatumAspect::*)(Standard_Boolean)) &Prs3d_DatumAspect::SetDrawThirdAxis, "Sets the DrawThirdAxis attributes to active.", py::arg("theToDraw"));
cls_Prs3d_DatumAspect.def("DrawThirdAxis", (Standard_Boolean (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::DrawThirdAxis, "Returns true if the third axis can be drawn.");
cls_Prs3d_DatumAspect.def("DrawDatumPart", (Standard_Boolean (Prs3d_DatumAspect::*)(Prs3d_DatumParts) const) &Prs3d_DatumAspect::DrawDatumPart, "Returns true if the given part is used in axes of aspect", py::arg("thePart"));
cls_Prs3d_DatumAspect.def("SetDrawDatumAxes", (void (Prs3d_DatumAspect::*)(Prs3d_DatumAxes)) &Prs3d_DatumAspect::SetDrawDatumAxes, "Sets the axes used in the datum aspect", py::arg("theType"));
cls_Prs3d_DatumAspect.def("DatumAxes", (Prs3d_DatumAxes (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::DatumAxes, "Returns axes used in the datum aspect");
cls_Prs3d_DatumAspect.def("SetAttribute", (void (Prs3d_DatumAspect::*)(Prs3d_DatumAttribute, const Standard_Real &)) &Prs3d_DatumAspect::SetAttribute, "Sets the attribute of the datum type", py::arg("theType"), py::arg("theValue"));
cls_Prs3d_DatumAspect.def("Attribute", (Standard_Real (Prs3d_DatumAspect::*)(Prs3d_DatumAttribute) const) &Prs3d_DatumAspect::Attribute, "Returns the attribute of the datum type", py::arg("theType"));
cls_Prs3d_DatumAspect.def("SetAxisLength", (void (Prs3d_DatumAspect::*)(Standard_Real, Standard_Real, Standard_Real)) &Prs3d_DatumAspect::SetAxisLength, "Sets the lengths of the three axes.", py::arg("theL1"), py::arg("theL2"), py::arg("theL3"));
cls_Prs3d_DatumAspect.def("AxisLength", (Standard_Real (Prs3d_DatumAspect::*)(Prs3d_DatumParts) const) &Prs3d_DatumAspect::AxisLength, "Returns the length of the displayed first axis.", py::arg("thePart"));
cls_Prs3d_DatumAspect.def("FirstAxisLength", (Standard_Real (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::FirstAxisLength, "Returns the length of the displayed first axis.");
cls_Prs3d_DatumAspect.def("SecondAxisLength", (Standard_Real (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::SecondAxisLength, "Returns the length of the displayed second axis.");
cls_Prs3d_DatumAspect.def("ThirdAxisLength", (Standard_Real (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::ThirdAxisLength, "Returns the length of the displayed third axis.");
cls_Prs3d_DatumAspect.def("ToDrawLabels", (Standard_Boolean (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::ToDrawLabels, "Returns true if axes labels are drawn; TRUE by default.");
cls_Prs3d_DatumAspect.def("SetDrawLabels", (void (Prs3d_DatumAspect::*)(Standard_Boolean)) &Prs3d_DatumAspect::SetDrawLabels, "Sets option to draw or not to draw text labels for axes", py::arg("theToDraw"));
cls_Prs3d_DatumAspect.def("SetToDrawLabels", (void (Prs3d_DatumAspect::*)(Standard_Boolean)) &Prs3d_DatumAspect::SetToDrawLabels, "None", py::arg("theToDraw"));
cls_Prs3d_DatumAspect.def("ToDrawArrows", (Standard_Boolean (Prs3d_DatumAspect::*)() const) &Prs3d_DatumAspect::ToDrawArrows, "Returns true if axes arrows are drawn; TRUE by default.");
cls_Prs3d_DatumAspect.def("SetDrawArrows", (void (Prs3d_DatumAspect::*)(Standard_Boolean)) &Prs3d_DatumAspect::SetDrawArrows, "Sets option to draw or not arrows for axes", py::arg("theToDraw"));
cls_Prs3d_DatumAspect.def("ArrowPartForAxis", (Prs3d_DatumParts (Prs3d_DatumAspect::*)(Prs3d_DatumParts) const) &Prs3d_DatumAspect::ArrowPartForAxis, "Returns type of arrow for a type of axis", py::arg("thePart"));

// Enums

}