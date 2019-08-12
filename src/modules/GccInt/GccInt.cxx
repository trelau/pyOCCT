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

void bind_GccInt_IType(py::module &);
void bind_GccInt_Bisec(py::module &);
void bind_GccInt_BCirc(py::module &);
void bind_GccInt_BElips(py::module &);
void bind_GccInt_BHyper(py::module &);
void bind_GccInt_BLine(py::module &);
void bind_GccInt_BParab(py::module &);
void bind_GccInt_BPoint(py::module &);

PYBIND11_MODULE(GccInt, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");

bind_GccInt_IType(mod);
bind_GccInt_Bisec(mod);
bind_GccInt_BCirc(mod);
bind_GccInt_BElips(mod);
bind_GccInt_BHyper(mod);
bind_GccInt_BLine(mod);
bind_GccInt_BParab(mod);
bind_GccInt_BPoint(mod);

}
