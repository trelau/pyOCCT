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

void bind_GeomAdaptor_Surface(py::module &);
void bind_GeomAdaptor_Curve(py::module &);
void bind_GeomAdaptor_GHSurface(py::module &);
void bind_GeomAdaptor_HSurface(py::module &);
void bind_GeomAdaptor(py::module &);
void bind_GeomAdaptor_GHCurve(py::module &);
void bind_GeomAdaptor_HCurve(py::module &);
void bind_GeomAdaptor_SurfaceOfLinearExtrusion(py::module &);
void bind_GeomAdaptor_HSurfaceOfLinearExtrusion(py::module &);
void bind_GeomAdaptor_SurfaceOfRevolution(py::module &);
void bind_GeomAdaptor_HSurfaceOfRevolution(py::module &);

PYBIND11_MODULE(GeomAdaptor, mod) {

py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.BSplSLib");
py::module::import("OCCT.BSplCLib");

bind_GeomAdaptor_Surface(mod);
bind_GeomAdaptor_Curve(mod);
bind_GeomAdaptor_GHSurface(mod);
bind_GeomAdaptor_HSurface(mod);
bind_GeomAdaptor(mod);
bind_GeomAdaptor_GHCurve(mod);
bind_GeomAdaptor_HCurve(mod);
bind_GeomAdaptor_SurfaceOfLinearExtrusion(mod);
bind_GeomAdaptor_HSurfaceOfLinearExtrusion(mod);
bind_GeomAdaptor_SurfaceOfRevolution(mod);
bind_GeomAdaptor_HSurfaceOfRevolution(mod);

}
