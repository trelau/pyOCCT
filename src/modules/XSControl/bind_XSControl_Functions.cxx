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
#include <XSControl_Functions.hxx>

void bind_XSControl_Functions(py::module &mod){

py::class_<XSControl_Functions, std::unique_ptr<XSControl_Functions, Deleter<XSControl_Functions>>> cls_XSControl_Functions(mod, "XSControl_Functions", "Functions from XSControl gives access to actions which can be commanded with the resources provided by XSControl: especially Controller and Transfer");

// Constructors

// Fields

// Methods
cls_XSControl_Functions.def_static("Init_", (void (*)()) &XSControl_Functions::Init, "Defines and loads all functions for XSControl (as ActFunc)");

// Enums

}