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

void bind_BinMDataXtd(py::module &);
void bind_BinMDataXtd_AxisDriver(py::module &);
void bind_BinMDataXtd_ConstraintDriver(py::module &);
void bind_BinMDataXtd_GeometryDriver(py::module &);
void bind_BinMDataXtd_PatternStdDriver(py::module &);
void bind_BinMDataXtd_PlacementDriver(py::module &);
void bind_BinMDataXtd_PlaneDriver(py::module &);
void bind_BinMDataXtd_PointDriver(py::module &);
void bind_BinMDataXtd_PositionDriver(py::module &);
void bind_BinMDataXtd_PresentationDriver(py::module &);
void bind_BinMDataXtd_ShapeDriver(py::module &);
void bind_BinMDataXtd_TriangulationDriver(py::module &);

PYBIND11_MODULE(BinMDataXtd, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.BinMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.BinObjMgt");

bind_BinMDataXtd(mod);
bind_BinMDataXtd_AxisDriver(mod);
bind_BinMDataXtd_ConstraintDriver(mod);
bind_BinMDataXtd_GeometryDriver(mod);
bind_BinMDataXtd_PatternStdDriver(mod);
bind_BinMDataXtd_PlacementDriver(mod);
bind_BinMDataXtd_PlaneDriver(mod);
bind_BinMDataXtd_PointDriver(mod);
bind_BinMDataXtd_PositionDriver(mod);
bind_BinMDataXtd_PresentationDriver(mod);
bind_BinMDataXtd_ShapeDriver(mod);
bind_BinMDataXtd_TriangulationDriver(mod);

}
