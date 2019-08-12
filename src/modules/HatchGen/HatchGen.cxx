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

void bind_HatchGen_IntersectionType(py::module &);
void bind_HatchGen_ErrorStatus(py::module &);
void bind_HatchGen_IntersectionPoint(py::module &);
void bind_HatchGen_PointOnElement(py::module &);
void bind_HatchGen_PointsOnElement(py::module &);
void bind_HatchGen_PointOnHatching(py::module &);
void bind_HatchGen_PointsOnHatching(py::module &);
void bind_HatchGen_Domain(py::module &);
void bind_HatchGen_Domains(py::module &);

PYBIND11_MODULE(HatchGen, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.NCollection");

bind_HatchGen_IntersectionType(mod);
bind_HatchGen_ErrorStatus(mod);
bind_HatchGen_IntersectionPoint(mod);
bind_HatchGen_PointOnElement(mod);
bind_HatchGen_PointsOnElement(mod);
bind_HatchGen_PointOnHatching(mod);
bind_HatchGen_PointsOnHatching(mod);
bind_HatchGen_Domain(mod);
bind_HatchGen_Domains(mod);

}
