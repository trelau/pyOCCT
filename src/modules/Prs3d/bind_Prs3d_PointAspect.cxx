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
#include <Prs3d_PointAspect.hxx>
#include <Standard_Type.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Graphic3d_MarkerImage.hxx>

void bind_Prs3d_PointAspect(py::module &mod){

py::class_<Prs3d_PointAspect, opencascade::handle<Prs3d_PointAspect>, Prs3d_BasicAspect> cls_Prs3d_PointAspect(mod, "Prs3d_PointAspect", "This class defines attributes for the points The points are drawn using markers, whose size does not depend on the zoom value of the views.");

// Constructors
cls_Prs3d_PointAspect.def(py::init<const Aspect_TypeOfMarker, const Quantity_Color &, const Standard_Real>(), py::arg("theType"), py::arg("theColor"), py::arg("theScale"));
cls_Prs3d_PointAspect.def(py::init<const Quantity_Color &, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfByte> &>(), py::arg("theColor"), py::arg("theWidth"), py::arg("theHeight"), py::arg("theTexture"));
cls_Prs3d_PointAspect.def(py::init<const opencascade::handle<Graphic3d_AspectMarker3d> &>(), py::arg("theAspect"));

// Fields

// Methods
cls_Prs3d_PointAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_PointAspect::get_type_name, "None");
cls_Prs3d_PointAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_PointAspect::get_type_descriptor, "None");
cls_Prs3d_PointAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_PointAspect::*)() const) &Prs3d_PointAspect::DynamicType, "None");
cls_Prs3d_PointAspect.def("SetColor", (void (Prs3d_PointAspect::*)(const Quantity_Color &)) &Prs3d_PointAspect::SetColor, "defines the color to be used when drawing a point. Default value: Quantity_NOC_YELLOW", py::arg("theColor"));
cls_Prs3d_PointAspect.def("SetTypeOfMarker", (void (Prs3d_PointAspect::*)(const Aspect_TypeOfMarker)) &Prs3d_PointAspect::SetTypeOfMarker, "defines the type of representation to be used when drawing a point. Default value: Aspect_TOM_PLUS", py::arg("theType"));
cls_Prs3d_PointAspect.def("SetScale", (void (Prs3d_PointAspect::*)(const Standard_Real)) &Prs3d_PointAspect::SetScale, "defines the size of the marker used when drawing a point. Default value: 1.", py::arg("theScale"));
cls_Prs3d_PointAspect.def("Aspect", (const opencascade::handle<Graphic3d_AspectMarker3d> & (Prs3d_PointAspect::*)() const) &Prs3d_PointAspect::Aspect, "None");
cls_Prs3d_PointAspect.def("SetAspect", (void (Prs3d_PointAspect::*)(const opencascade::handle<Graphic3d_AspectMarker3d> &)) &Prs3d_PointAspect::SetAspect, "None", py::arg("theAspect"));
cls_Prs3d_PointAspect.def("GetTextureSize", [](Prs3d_PointAspect &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.GetTextureSize(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "Returns marker's texture size.", py::arg("theWidth"), py::arg("theHeight"));
cls_Prs3d_PointAspect.def("GetTexture", (const opencascade::handle<Graphic3d_MarkerImage> & (Prs3d_PointAspect::*)() const) &Prs3d_PointAspect::GetTexture, "Returns marker's texture.");

// Enums

}