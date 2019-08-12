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

void bind_ProjLib(py::module &);
void bind_ProjLib_SequenceOfHSequenceOfPnt(py::module &);
void bind_ProjLib_HSequenceOfHSequenceOfPnt(py::module &);
void bind_ProjLib_CompProjectedCurve(py::module &);
void bind_ProjLib_ComputeApprox(py::module &);
void bind_ProjLib_ComputeApproxOnPolarSurface(py::module &);
void bind_ProjLib_Projector(py::module &);
void bind_ProjLib_Cone(py::module &);
void bind_ProjLib_Cylinder(py::module &);
void bind_ProjLib_HCompProjectedCurve(py::module &);
void bind_ProjLib_ProjectedCurve(py::module &);
void bind_ProjLib_HProjectedCurve(py::module &);
void bind_ProjLib_Plane(py::module &);
void bind_ProjLib_PrjFunc(py::module &);
void bind_ProjLib_PrjResolve(py::module &);
void bind_ProjLib_ProjectOnPlane(py::module &);
void bind_ProjLib_ProjectOnSurface(py::module &);
void bind_ProjLib_Sphere(py::module &);
void bind_ProjLib_Torus(py::module &);

PYBIND11_MODULE(ProjLib, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.AppParCurves");
py::module::import("OCCT.math");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.Geom");

bind_ProjLib(mod);
bind_ProjLib_SequenceOfHSequenceOfPnt(mod);
bind_ProjLib_HSequenceOfHSequenceOfPnt(mod);
bind_ProjLib_CompProjectedCurve(mod);
bind_ProjLib_ComputeApprox(mod);
bind_ProjLib_ComputeApproxOnPolarSurface(mod);
bind_ProjLib_Projector(mod);
bind_ProjLib_Cone(mod);
bind_ProjLib_Cylinder(mod);
bind_ProjLib_HCompProjectedCurve(mod);
bind_ProjLib_ProjectedCurve(mod);
bind_ProjLib_HProjectedCurve(mod);
bind_ProjLib_Plane(mod);
bind_ProjLib_PrjFunc(mod);
bind_ProjLib_PrjResolve(mod);
bind_ProjLib_ProjectOnPlane(mod);
bind_ProjLib_ProjectOnSurface(mod);
bind_ProjLib_Sphere(mod);
bind_ProjLib_Torus(mod);

}
