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
#include <Standard_CLocaleSentry.hxx>

void bind_Standard_CLocaleSentry(py::module &mod){

py::class_<Standard_CLocaleSentry, std::unique_ptr<Standard_CLocaleSentry, Deleter<Standard_CLocaleSentry>>> cls_Standard_CLocaleSentry(mod, "Standard_CLocaleSentry", "This class intended to temporary switch C locale and logically equivalent to setlocale(LC_ALL, 'C'). It is intended to format text regardless of user locale settings (for import/export functionality). Thus following calls to sprintf, atoi and other functions will use 'C' locale. Destructor of this class will return original locale.");

// Constructors
cls_Standard_CLocaleSentry.def(py::init<>());

// Fields

// Methods
cls_Standard_CLocaleSentry.def_static("GetCLocale_", (Standard_CLocaleSentry::clocale_t (*)()) &Standard_CLocaleSentry::GetCLocale, "Returns locale 'C' instance (locale_t within xlocale or _locale_t within Windows) to be used for _l functions with locale argument.");

// Enums

}