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

void bind_ShapeCustom(py::module &);
void bind_ShapeCustom_Modification(py::module &);
void bind_ShapeCustom_BSplineRestriction(py::module &);
void bind_ShapeCustom_ConvertToBSpline(py::module &);
void bind_ShapeCustom_ConvertToRevolution(py::module &);
void bind_ShapeCustom_Curve(py::module &);
void bind_ShapeCustom_Curve2d(py::module &);
void bind_ShapeCustom_DirectModification(py::module &);
void bind_ShapeCustom_RestrictionParameters(py::module &);
void bind_ShapeCustom_Surface(py::module &);
void bind_ShapeCustom_SweptToElementary(py::module &);
void bind_ShapeCustom_TrsfModification(py::module &);

PYBIND11_MODULE(ShapeCustom, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Message");
py::module::import("OCCT.ShapeBuild");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.ShapeExtend");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");

bind_ShapeCustom(mod);
bind_ShapeCustom_Modification(mod);
bind_ShapeCustom_BSplineRestriction(mod);
bind_ShapeCustom_ConvertToBSpline(mod);
bind_ShapeCustom_ConvertToRevolution(mod);
bind_ShapeCustom_Curve(mod);
bind_ShapeCustom_Curve2d(mod);
bind_ShapeCustom_DirectModification(mod);
bind_ShapeCustom_RestrictionParameters(mod);
bind_ShapeCustom_Surface(mod);
bind_ShapeCustom_SweptToElementary(mod);
bind_ShapeCustom_TrsfModification(mod);

}
