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

void bind_GProp_ValueType(py::module &);
void bind_GProp_EquaType(py::module &);
void bind_GProp_GProps(py::module &);
void bind_GProp(py::module &);
void bind_GProp_CelGProps(py::module &);
void bind_GProp_PEquation(py::module &);
void bind_GProp_PGProps(py::module &);
void bind_GProp_PrincipalProps(py::module &);
void bind_GProp_SelGProps(py::module &);
void bind_GProp_UndefinedAxis(py::module &);
void bind_GProp_VelGProps(py::module &);

PYBIND11_MODULE(GProp, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");

bind_GProp_ValueType(mod);
bind_GProp_EquaType(mod);
bind_GProp_GProps(mod);
bind_GProp(mod);
bind_GProp_CelGProps(mod);
bind_GProp_PEquation(mod);
bind_GProp_PGProps(mod);
bind_GProp_PrincipalProps(mod);
bind_GProp_SelGProps(mod);
bind_GProp_UndefinedAxis(mod);
bind_GProp_VelGProps(mod);

}
