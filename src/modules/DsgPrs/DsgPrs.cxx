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

void bind_DsgPrs_ArrowSide(py::module &);
void bind_DsgPrs(py::module &);
void bind_DsgPrs_AnglePresentation(py::module &);
void bind_DsgPrs_Chamf2dPresentation(py::module &);
void bind_DsgPrs_ConcentricPresentation(py::module &);
void bind_DsgPrs_DatumPrs(py::module &);
void bind_DsgPrs_DiameterPresentation(py::module &);
void bind_DsgPrs_EllipseRadiusPresentation(py::module &);
void bind_DsgPrs_EqualDistancePresentation(py::module &);
void bind_DsgPrs_EqualRadiusPresentation(py::module &);
void bind_DsgPrs_FilletRadiusPresentation(py::module &);
void bind_DsgPrs_FixPresentation(py::module &);
void bind_DsgPrs_IdenticPresentation(py::module &);
void bind_DsgPrs_LengthPresentation(py::module &);
void bind_DsgPrs_MidPointPresentation(py::module &);
void bind_DsgPrs_OffsetPresentation(py::module &);
void bind_DsgPrs_ParalPresentation(py::module &);
void bind_DsgPrs_PerpenPresentation(py::module &);
void bind_DsgPrs_RadiusPresentation(py::module &);
void bind_DsgPrs_ShadedPlanePresentation(py::module &);
void bind_DsgPrs_ShapeDirPresentation(py::module &);
void bind_DsgPrs_SymbPresentation(py::module &);
void bind_DsgPrs_SymmetricPresentation(py::module &);
void bind_DsgPrs_TangentPresentation(py::module &);
void bind_DsgPrs_XYZAxisPresentation(py::module &);
void bind_DsgPrs_XYZPlanePresentation(py::module &);

PYBIND11_MODULE(DsgPrs, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TopoDS");

bind_DsgPrs_ArrowSide(mod);
bind_DsgPrs(mod);
bind_DsgPrs_AnglePresentation(mod);
bind_DsgPrs_Chamf2dPresentation(mod);
bind_DsgPrs_ConcentricPresentation(mod);
bind_DsgPrs_DatumPrs(mod);
bind_DsgPrs_DiameterPresentation(mod);
bind_DsgPrs_EllipseRadiusPresentation(mod);
bind_DsgPrs_EqualDistancePresentation(mod);
bind_DsgPrs_EqualRadiusPresentation(mod);
bind_DsgPrs_FilletRadiusPresentation(mod);
bind_DsgPrs_FixPresentation(mod);
bind_DsgPrs_IdenticPresentation(mod);
bind_DsgPrs_LengthPresentation(mod);
bind_DsgPrs_MidPointPresentation(mod);
bind_DsgPrs_OffsetPresentation(mod);
bind_DsgPrs_ParalPresentation(mod);
bind_DsgPrs_PerpenPresentation(mod);
bind_DsgPrs_RadiusPresentation(mod);
bind_DsgPrs_ShadedPlanePresentation(mod);
bind_DsgPrs_ShapeDirPresentation(mod);
bind_DsgPrs_SymbPresentation(mod);
bind_DsgPrs_SymmetricPresentation(mod);
bind_DsgPrs_TangentPresentation(mod);
bind_DsgPrs_XYZAxisPresentation(mod);
bind_DsgPrs_XYZPlanePresentation(mod);

}
