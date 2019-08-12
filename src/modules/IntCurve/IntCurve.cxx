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

void bind_IntCurve_IntImpConicParConic(py::module &);
void bind_IntCurve_IntConicConic(py::module &);
void bind_IntCurve_IConicTool(py::module &);
void bind_IntCurve_PConic(py::module &);
void bind_Interval(py::module &);
void bind_PeriodicInterval(py::module &);
void bind_IntCurve_MyImpParToolOfIntImpConicParConic(py::module &);
void bind_IntCurve_PConicTool(py::module &);
void bind_IntCurve_ProjectOnPConicTool(py::module &);

PYBIND11_MODULE(IntCurve, mod) {

py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.math");

bind_IntCurve_IntImpConicParConic(mod);
bind_IntCurve_IntConicConic(mod);
bind_IntCurve_IConicTool(mod);
bind_IntCurve_PConic(mod);
bind_Interval(mod);
bind_PeriodicInterval(mod);
bind_IntCurve_MyImpParToolOfIntImpConicParConic(mod);
bind_IntCurve_PConicTool(mod);
bind_IntCurve_ProjectOnPConicTool(mod);

}
