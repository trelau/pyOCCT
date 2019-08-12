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

void bind_TransferBRep_TransferResultInfo(py::module &);
void bind_TransferBRep_SequenceOfTransferResultInfo(py::module &);
void bind_TransferBRep_HSequenceOfTransferResultInfo(py::module &);
void bind_TransferBRep(py::module &);
void bind_TransferBRep_BinderOfShape(py::module &);
void bind_TransferBRep_OrientedShapeMapper(py::module &);
void bind_TransferBRep_Reader(py::module &);
void bind_TransferBRep_ShapeBinder(py::module &);
void bind_TransferBRep_ShapeInfo(py::module &);
void bind_TransferBRep_ShapeListBinder(py::module &);
void bind_TransferBRep_ShapeMapper(py::module &);

PYBIND11_MODULE(TransferBRep, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Transfer");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Message");
py::module::import("OCCT.Interface");

bind_TransferBRep_TransferResultInfo(mod);
bind_TransferBRep_SequenceOfTransferResultInfo(mod);
bind_TransferBRep_HSequenceOfTransferResultInfo(mod);
bind_TransferBRep(mod);
bind_TransferBRep_BinderOfShape(mod);
bind_TransferBRep_OrientedShapeMapper(mod);
bind_TransferBRep_Reader(mod);
bind_TransferBRep_ShapeBinder(mod);
bind_TransferBRep_ShapeInfo(mod);
bind_TransferBRep_ShapeListBinder(mod);
bind_TransferBRep_ShapeMapper(mod);

}
