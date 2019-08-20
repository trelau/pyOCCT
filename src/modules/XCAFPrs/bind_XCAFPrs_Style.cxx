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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <XCAFPrs_Style.hxx>
#include <Quantity_ColorRGBAHasher.hxx>
#include <Quantity_ColorHasher.hxx>

void bind_XCAFPrs_Style(py::module &mod){

py::class_<XCAFPrs_Style, std::unique_ptr<XCAFPrs_Style>> cls_XCAFPrs_Style(mod, "XCAFPrs_Style", "Represents a set of styling settings applicable to a (sub)shape");

// Constructors
cls_XCAFPrs_Style.def(py::init<>());

// Fields

// Methods
// cls_XCAFPrs_Style.def_static("operator new_", (void * (*)(size_t)) &XCAFPrs_Style::operator new, "None", py::arg("theSize"));
// cls_XCAFPrs_Style.def_static("operator delete_", (void (*)(void *)) &XCAFPrs_Style::operator delete, "None", py::arg("theAddress"));
// cls_XCAFPrs_Style.def_static("operator new[]_", (void * (*)(size_t)) &XCAFPrs_Style::operator new[], "None", py::arg("theSize"));
// cls_XCAFPrs_Style.def_static("operator delete[]_", (void (*)(void *)) &XCAFPrs_Style::operator delete[], "None", py::arg("theAddress"));
// cls_XCAFPrs_Style.def_static("operator new_", (void * (*)(size_t, void *)) &XCAFPrs_Style::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XCAFPrs_Style.def_static("operator delete_", (void (*)(void *, void *)) &XCAFPrs_Style::operator delete, "None", py::arg(""), py::arg(""));
cls_XCAFPrs_Style.def("IsSetColorSurf", (Standard_Boolean (XCAFPrs_Style::*)() const) &XCAFPrs_Style::IsSetColorSurf, "Return TRUE if surface color has been defined.");
cls_XCAFPrs_Style.def("GetColorSurf", (const Quantity_Color & (XCAFPrs_Style::*)() const) &XCAFPrs_Style::GetColorSurf, "Return surface color.");
cls_XCAFPrs_Style.def("SetColorSurf", (void (XCAFPrs_Style::*)(const Quantity_Color &)) &XCAFPrs_Style::SetColorSurf, "Set surface color.", py::arg("theColor"));
cls_XCAFPrs_Style.def("GetColorSurfRGBA", (const Quantity_ColorRGBA & (XCAFPrs_Style::*)() const) &XCAFPrs_Style::GetColorSurfRGBA, "Return surface color.");
cls_XCAFPrs_Style.def("SetColorSurf", (void (XCAFPrs_Style::*)(const Quantity_ColorRGBA &)) &XCAFPrs_Style::SetColorSurf, "Set surface color.", py::arg("theColor"));
cls_XCAFPrs_Style.def("UnSetColorSurf", (void (XCAFPrs_Style::*)()) &XCAFPrs_Style::UnSetColorSurf, "Manage surface color setting");
cls_XCAFPrs_Style.def("IsSetColorCurv", (Standard_Boolean (XCAFPrs_Style::*)() const) &XCAFPrs_Style::IsSetColorCurv, "Return TRUE if curve color has been defined.");
cls_XCAFPrs_Style.def("GetColorCurv", (const Quantity_Color & (XCAFPrs_Style::*)() const) &XCAFPrs_Style::GetColorCurv, "Return curve color.");
cls_XCAFPrs_Style.def("SetColorCurv", (void (XCAFPrs_Style::*)(const Quantity_Color &)) &XCAFPrs_Style::SetColorCurv, "Set curve color.", py::arg("col"));
cls_XCAFPrs_Style.def("UnSetColorCurv", (void (XCAFPrs_Style::*)()) &XCAFPrs_Style::UnSetColorCurv, "Manage curve color setting");
cls_XCAFPrs_Style.def("SetVisibility", (void (XCAFPrs_Style::*)(const Standard_Boolean)) &XCAFPrs_Style::SetVisibility, "Assign visibility.", py::arg("theVisibility"));
cls_XCAFPrs_Style.def("IsVisible", (Standard_Boolean (XCAFPrs_Style::*)() const) &XCAFPrs_Style::IsVisible, "Manage visibility.");
cls_XCAFPrs_Style.def("IsEqual", (Standard_Boolean (XCAFPrs_Style::*)(const XCAFPrs_Style &) const) &XCAFPrs_Style::IsEqual, "Returns True if styles are the same Methods for using Style as key in maps", py::arg("theOther"));
cls_XCAFPrs_Style.def("__eq__", (Standard_Boolean (XCAFPrs_Style::*)(const XCAFPrs_Style &) const) &XCAFPrs_Style::operator==, py::is_operator(), "Returns True if styles are the same.", py::arg("theOther"));
cls_XCAFPrs_Style.def_static("HashCode_", (Standard_Integer (*)(const XCAFPrs_Style &, const Standard_Integer)) &XCAFPrs_Style::HashCode, "Returns a HasCode value.", py::arg("theStyle"), py::arg("theUpper"));
cls_XCAFPrs_Style.def_static("IsEqual_", (Standard_Boolean (*)(const XCAFPrs_Style &, const XCAFPrs_Style &)) &XCAFPrs_Style::IsEqual, "Returns True when the two keys are the same.", py::arg("theS1"), py::arg("theS2"));

// Enums

}