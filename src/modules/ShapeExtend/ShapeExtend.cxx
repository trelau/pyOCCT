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

void bind_ShapeExtend_Status(py::module &);
void bind_ShapeExtend_Parametrisation(py::module &);
void bind_ShapeExtend_BasicMsgRegistrator(py::module &);
void bind_ShapeExtend(py::module &);
void bind_ShapeExtend_WireData(py::module &);
void bind_ShapeExtend_ComplexCurve(py::module &);
void bind_ShapeExtend_CompositeSurface(py::module &);
void bind_ShapeExtend_DataMapOfShapeListOfMsg(py::module &);
void bind_ShapeExtend_DataMapIteratorOfDataMapOfShapeListOfMsg(py::module &);
void bind_ShapeExtend_DataMapOfTransientListOfMsg(py::module &);
void bind_ShapeExtend_DataMapIteratorOfDataMapOfTransientListOfMsg(py::module &);
void bind_ShapeExtend_Explorer(py::module &);
void bind_ShapeExtend_MsgRegistrator(py::module &);

PYBIND11_MODULE(ShapeExtend, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Message");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColGeom");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopAbs");

bind_ShapeExtend_Status(mod);
bind_ShapeExtend_Parametrisation(mod);
bind_ShapeExtend_BasicMsgRegistrator(mod);
bind_ShapeExtend(mod);
bind_ShapeExtend_WireData(mod);
bind_ShapeExtend_ComplexCurve(mod);
bind_ShapeExtend_CompositeSurface(mod);
bind_ShapeExtend_DataMapOfShapeListOfMsg(mod);
bind_ShapeExtend_DataMapIteratorOfDataMapOfShapeListOfMsg(mod);
bind_ShapeExtend_DataMapOfTransientListOfMsg(mod);
bind_ShapeExtend_DataMapIteratorOfDataMapOfTransientListOfMsg(mod);
bind_ShapeExtend_Explorer(mod);
bind_ShapeExtend_MsgRegistrator(mod);

}
