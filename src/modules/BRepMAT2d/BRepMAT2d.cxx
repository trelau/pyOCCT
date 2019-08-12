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

void bind_BRepMAT2d_BisectingLocus(py::module &);
void bind_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt(py::module &);
void bind_BRepMAT2d_DataMapIteratorOfDataMapOfShapeSequenceOfBasicElt(py::module &);
void bind_BRepMAT2d_DataMapOfBasicEltShape(py::module &);
void bind_BRepMAT2d_DataMapIteratorOfDataMapOfBasicEltShape(py::module &);
void bind_BRepMAT2d_LinkTopoBilo(py::module &);
void bind_BRepMAT2d_Explorer(py::module &);

PYBIND11_MODULE(BRepMAT2d, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.MAT");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.Bisector");
py::module::import("OCCT.MAT2d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColGeom2d");

bind_BRepMAT2d_BisectingLocus(mod);
bind_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt(mod);
bind_BRepMAT2d_DataMapIteratorOfDataMapOfShapeSequenceOfBasicElt(mod);
bind_BRepMAT2d_DataMapOfBasicEltShape(mod);
bind_BRepMAT2d_DataMapIteratorOfDataMapOfBasicEltShape(mod);
bind_BRepMAT2d_LinkTopoBilo(mod);
bind_BRepMAT2d_Explorer(mod);

}
