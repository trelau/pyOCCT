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

void bind_TDataXtd_GeometryEnum(py::module &);
void bind_TDataXtd_ConstraintEnum(py::module &);
void bind_TDataXtd_Shape(py::module &);
void bind_TDataXtd_Point(py::module &);
void bind_TDataXtd_Axis(py::module &);
void bind_TDataXtd_Plane(py::module &);
void bind_TDataXtd_Placement(py::module &);
void bind_TDataXtd_Geometry(py::module &);
void bind_TDataXtd_Position(py::module &);
void bind_TDataXtd_Constraint(py::module &);
void bind_TDataXtd_Array1OfTrsf(py::module &);
void bind_TDataXtd_Pattern(py::module &);
void bind_TDataXtd_PatternStd(py::module &);
void bind_TDataXtd_Presentation(py::module &);
void bind_TDataXtd(py::module &);
void bind_TDataXtd_HArray1OfTrsf(py::module &);
void bind_TDataXtd_Triangulation(py::module &);

PYBIND11_MODULE(TDataXtd, mod) {

py::module::import("OCCT.TDF");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.TNaming");
py::module::import("OCCT.TDataStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.Poly");
py::module::import("OCCT.TShort");

bind_TDataXtd_GeometryEnum(mod);
bind_TDataXtd_ConstraintEnum(mod);
bind_TDataXtd_Shape(mod);
bind_TDataXtd_Point(mod);
bind_TDataXtd_Axis(mod);
bind_TDataXtd_Plane(mod);
bind_TDataXtd_Placement(mod);
bind_TDataXtd_Geometry(mod);
bind_TDataXtd_Position(mod);
bind_TDataXtd_Constraint(mod);
bind_TDataXtd_Array1OfTrsf(mod);
bind_TDataXtd_Pattern(mod);
bind_TDataXtd_PatternStd(mod);
bind_TDataXtd_Presentation(mod);
bind_TDataXtd(mod);
bind_TDataXtd_HArray1OfTrsf(mod);
bind_TDataXtd_Triangulation(mod);

}
