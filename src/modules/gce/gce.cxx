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

void bind_gce_ErrorType(py::module &);
void bind_gce_Root(py::module &);
void bind_gce_MakeCirc(py::module &);
void bind_gce_MakeCirc2d(py::module &);
void bind_gce_MakeCone(py::module &);
void bind_gce_MakeCylinder(py::module &);
void bind_gce_MakeDir(py::module &);
void bind_gce_MakeDir2d(py::module &);
void bind_gce_MakeElips(py::module &);
void bind_gce_MakeElips2d(py::module &);
void bind_gce_MakeHypr(py::module &);
void bind_gce_MakeHypr2d(py::module &);
void bind_gce_MakeLin(py::module &);
void bind_gce_MakeLin2d(py::module &);
void bind_gce_MakeMirror(py::module &);
void bind_gce_MakeMirror2d(py::module &);
void bind_gce_MakeParab(py::module &);
void bind_gce_MakeParab2d(py::module &);
void bind_gce_MakePln(py::module &);
void bind_gce_MakeRotation(py::module &);
void bind_gce_MakeRotation2d(py::module &);
void bind_gce_MakeScale(py::module &);
void bind_gce_MakeScale2d(py::module &);
void bind_gce_MakeTranslation(py::module &);
void bind_gce_MakeTranslation2d(py::module &);

PYBIND11_MODULE(gce, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");

bind_gce_ErrorType(mod);
bind_gce_Root(mod);
bind_gce_MakeCirc(mod);
bind_gce_MakeCirc2d(mod);
bind_gce_MakeCone(mod);
bind_gce_MakeCylinder(mod);
bind_gce_MakeDir(mod);
bind_gce_MakeDir2d(mod);
bind_gce_MakeElips(mod);
bind_gce_MakeElips2d(mod);
bind_gce_MakeHypr(mod);
bind_gce_MakeHypr2d(mod);
bind_gce_MakeLin(mod);
bind_gce_MakeLin2d(mod);
bind_gce_MakeMirror(mod);
bind_gce_MakeMirror2d(mod);
bind_gce_MakeParab(mod);
bind_gce_MakeParab2d(mod);
bind_gce_MakePln(mod);
bind_gce_MakeRotation(mod);
bind_gce_MakeRotation2d(mod);
bind_gce_MakeScale(mod);
bind_gce_MakeScale2d(mod);
bind_gce_MakeTranslation(mod);
bind_gce_MakeTranslation2d(mod);

}
