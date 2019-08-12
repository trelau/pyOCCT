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

void bind_HLRTopoBRep_FaceData(py::module &);
void bind_HLRTopoBRep_DataMapOfShapeFaceData(py::module &);
void bind_HLRTopoBRep_DataMapIteratorOfDataMapOfShapeFaceData(py::module &);
void bind_HLRTopoBRep_VData(py::module &);
void bind_HLRTopoBRep_ListOfVData(py::module &);
void bind_HLRTopoBRep_ListIteratorOfListOfVData(py::module &);
void bind_HLRTopoBRep_MapOfShapeListOfVData(py::module &);
void bind_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData(py::module &);
void bind_HLRTopoBRep_Data(py::module &);
void bind_HLRTopoBRep_DSFiller(py::module &);
void bind_HLRTopoBRep_FaceIsoLiner(py::module &);
void bind_HLRTopoBRep_OutLiner(py::module &);

PYBIND11_MODULE(HLRTopoBRep, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Contap");
py::module::import("OCCT.BRepTopAdaptor");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.HLRAlgo");

bind_HLRTopoBRep_FaceData(mod);
bind_HLRTopoBRep_DataMapOfShapeFaceData(mod);
bind_HLRTopoBRep_DataMapIteratorOfDataMapOfShapeFaceData(mod);
bind_HLRTopoBRep_VData(mod);
bind_HLRTopoBRep_ListOfVData(mod);
bind_HLRTopoBRep_ListIteratorOfListOfVData(mod);
bind_HLRTopoBRep_MapOfShapeListOfVData(mod);
bind_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData(mod);
bind_HLRTopoBRep_Data(mod);
bind_HLRTopoBRep_DSFiller(mod);
bind_HLRTopoBRep_FaceIsoLiner(mod);
bind_HLRTopoBRep_OutLiner(mod);

}
