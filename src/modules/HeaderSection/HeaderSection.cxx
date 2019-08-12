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

void bind_HeaderSection(py::module &);
void bind_HeaderSection_FileDescription(py::module &);
void bind_HeaderSection_FileName(py::module &);
void bind_HeaderSection_FileSchema(py::module &);
void bind_HeaderSection_HeaderRecognizer(py::module &);
void bind_HeaderSection_Protocol(py::module &);

PYBIND11_MODULE(HeaderSection, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Interface");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepData");

bind_HeaderSection(mod);
bind_HeaderSection_FileDescription(mod);
bind_HeaderSection_FileName(mod);
bind_HeaderSection_FileSchema(mod);
bind_HeaderSection_HeaderRecognizer(mod);
bind_HeaderSection_Protocol(mod);

}
