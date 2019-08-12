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

void bind_GeomAbs_Shape(py::module &);
void bind_GeomAbs_CurveType(py::module &);
void bind_GeomAbs_BSplKnotDistribution(py::module &);
void bind_GeomAbs_IsoType(py::module &);
void bind_GeomAbs_SurfaceType(py::module &);
void bind_GeomAbs_JoinType(py::module &);
void bind_GeomAbs_CurveForm(py::module &);
void bind_GeomAbs_SurfaceForm(py::module &);
void bind_GeomAbs_UVSense(py::module &);

PYBIND11_MODULE(GeomAbs, mod) {


bind_GeomAbs_Shape(mod);
bind_GeomAbs_CurveType(mod);
bind_GeomAbs_BSplKnotDistribution(mod);
bind_GeomAbs_IsoType(mod);
bind_GeomAbs_SurfaceType(mod);
bind_GeomAbs_JoinType(mod);
bind_GeomAbs_CurveForm(mod);
bind_GeomAbs_SurfaceForm(mod);
bind_GeomAbs_UVSense(mod);

}
