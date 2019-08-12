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

void bind_IGESToBRep_AlgoContainer(py::module &);
void bind_IGESToBRep_CurveAndSurface(py::module &);
void bind_IGESToBRep_IGESBoundary(py::module &);
void bind_IGESToBRep_ToolContainer(py::module &);
void bind_IGESToBRep(py::module &);
void bind_IGESToBRep_Actor(py::module &);
void bind_IGESToBRep_BasicCurve(py::module &);
void bind_IGESToBRep_BasicSurface(py::module &);
void bind_IGESToBRep_BRepEntity(py::module &);
void bind_IGESToBRep_Reader(py::module &);
void bind_IGESToBRep_TopoCurve(py::module &);
void bind_IGESToBRep_TopoSurface(py::module &);

PYBIND11_MODULE(IGESToBRep, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.IGESData");
py::module::import("OCCT.Transfer");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Message");
py::module::import("OCCT.Geom");
py::module::import("OCCT.gp");
py::module::import("OCCT.ShapeExtend");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Interface");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.IGESGeom");
py::module::import("OCCT.IGESSolid");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TColGeom");
py::module::import("OCCT.TColGeom2d");
py::module::import("OCCT.IGESBasic");

bind_IGESToBRep_AlgoContainer(mod);
bind_IGESToBRep_CurveAndSurface(mod);
bind_IGESToBRep_IGESBoundary(mod);
bind_IGESToBRep_ToolContainer(mod);
bind_IGESToBRep(mod);
bind_IGESToBRep_Actor(mod);
bind_IGESToBRep_BasicCurve(mod);
bind_IGESToBRep_BasicSurface(mod);
bind_IGESToBRep_BRepEntity(mod);
bind_IGESToBRep_Reader(mod);
bind_IGESToBRep_TopoCurve(mod);
bind_IGESToBRep_TopoSurface(mod);

}
