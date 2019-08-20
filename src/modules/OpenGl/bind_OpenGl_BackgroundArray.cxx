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
#include <OpenGl_PrimitiveArray.hxx>
#include <Graphic3d_TypeOfBackground.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Workspace.hxx>
#include <Aspect_FillMethod.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <OpenGl_Vec.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <OpenGl_BackgroundArray.hxx>

void bind_OpenGl_BackgroundArray(py::module &mod){

py::class_<OpenGl_BackgroundArray, std::unique_ptr<OpenGl_BackgroundArray>, OpenGl_PrimitiveArray> cls_OpenGl_BackgroundArray(mod, "OpenGl_BackgroundArray", "Tool class for generating reusable data for gradient or texture background rendering.");

// Constructors
cls_OpenGl_BackgroundArray.def(py::init<const Graphic3d_TypeOfBackground>(), py::arg("theType"));

// Fields

// Methods
cls_OpenGl_BackgroundArray.def("Render", (void (OpenGl_BackgroundArray::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_BackgroundArray::Render, "Render primitives to the window", py::arg("theWorkspace"));
cls_OpenGl_BackgroundArray.def("IsDefined", (bool (OpenGl_BackgroundArray::*)() const) &OpenGl_BackgroundArray::IsDefined, "Check if background parameters are set properly");
cls_OpenGl_BackgroundArray.def("SetTextureParameters", (void (OpenGl_BackgroundArray::*)(const Aspect_FillMethod)) &OpenGl_BackgroundArray::SetTextureParameters, "Sets background texture parameters", py::arg("theFillMethod"));
cls_OpenGl_BackgroundArray.def("SetTextureFillMethod", (void (OpenGl_BackgroundArray::*)(const Aspect_FillMethod)) &OpenGl_BackgroundArray::SetTextureFillMethod, "Sets texture fill method", py::arg("theFillMethod"));
cls_OpenGl_BackgroundArray.def("TextureFillMethod", (Aspect_FillMethod (OpenGl_BackgroundArray::*)() const) &OpenGl_BackgroundArray::TextureFillMethod, "Gets background texture fill method");
cls_OpenGl_BackgroundArray.def("GradientFillMethod", (Aspect_GradientFillMethod (OpenGl_BackgroundArray::*)() const) &OpenGl_BackgroundArray::GradientFillMethod, "Gets background gradient fill method");
cls_OpenGl_BackgroundArray.def("GradientColor", (const OpenGl_Vec4 & (OpenGl_BackgroundArray::*)(const Standard_Integer) const) &OpenGl_BackgroundArray::GradientColor, "Returns color of gradient background for the given index.", py::arg("theIndex"));
cls_OpenGl_BackgroundArray.def("SetGradientFillMethod", (void (OpenGl_BackgroundArray::*)(const Aspect_GradientFillMethod)) &OpenGl_BackgroundArray::SetGradientFillMethod, "Sets type of gradient fill method", py::arg("theType"));
cls_OpenGl_BackgroundArray.def("SetGradientParameters", (void (OpenGl_BackgroundArray::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod)) &OpenGl_BackgroundArray::SetGradientParameters, "Sets background gradient parameters", py::arg("theColor1"), py::arg("theColor2"), py::arg("theType"));

// Enums

}