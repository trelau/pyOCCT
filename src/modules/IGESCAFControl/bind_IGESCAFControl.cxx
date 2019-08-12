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
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESCAFControl_Reader.hxx>
#include <IGESCAFControl_Writer.hxx>
#include <IGESCAFControl.hxx>

void bind_IGESCAFControl(py::module &mod){

py::class_<IGESCAFControl, std::unique_ptr<IGESCAFControl, Deleter<IGESCAFControl>>> cls_IGESCAFControl(mod, "IGESCAFControl", "Provides high-level API to translate IGES file to and from DECAF document");

// Constructors

// Fields

// Methods
// cls_IGESCAFControl.def_static("operator new_", (void * (*)(size_t)) &IGESCAFControl::operator new, "None", py::arg("theSize"));
// cls_IGESCAFControl.def_static("operator delete_", (void (*)(void *)) &IGESCAFControl::operator delete, "None", py::arg("theAddress"));
// cls_IGESCAFControl.def_static("operator new[]_", (void * (*)(size_t)) &IGESCAFControl::operator new[], "None", py::arg("theSize"));
// cls_IGESCAFControl.def_static("operator delete[]_", (void (*)(void *)) &IGESCAFControl::operator delete[], "None", py::arg("theAddress"));
// cls_IGESCAFControl.def_static("operator new_", (void * (*)(size_t, void *)) &IGESCAFControl::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESCAFControl.def_static("operator delete_", (void (*)(void *, void *)) &IGESCAFControl::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESCAFControl.def_static("DecodeColor_", (Quantity_Color (*)(const Standard_Integer)) &IGESCAFControl::DecodeColor, "Provides a tool for writing IGES file Converts IGES color index to CASCADE color", py::arg("col"));
cls_IGESCAFControl.def_static("EncodeColor_", (Standard_Integer (*)(const Quantity_Color &)) &IGESCAFControl::EncodeColor, "Tries to Convert CASCADE color to IGES color index If no corresponding color defined in IGES, returns 0", py::arg("col"));

// Enums

}