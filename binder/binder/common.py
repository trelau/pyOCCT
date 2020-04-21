# This file is part of pyOCCT_binder which automatically generates Python
# bindings to the OpenCASCADE geometry kernel using pybind11.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)
# Copyright (C) 2019 Trevor Laughlin
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
import os
import json

SRC_PREFIX = """/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019-2020  Trevor Laughlin and the pyOCCT contributors

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
"""

# C++ to Python operators
PY_OPERATORS = {
    'operator+': '__add__',
    'operator-': '__sub__',
    'operator/': '__truediv__',
    'operator*': '__mul__',

    'operator+=': '__iadd__',
    'operator-=': '__isub__',
    'operator/=': '__itruediv__',
    'operator*=': '__imul__',

    # 'operator=': 'assign',
    'operator==': '__eq__',
    'operator()': '__call__',
    'operator!=': '__ne__',
    'operator[]': '__getitem__',
    'operator++': 'plus_plus',
    'operator--': 'minus_minus',
    'operator<': '__lt__',
    'operator<=': '__le__',
    'operator>': '__gt__',
    'operator>=': '__ge__',
    'operator>>': 'bits_right',
    'operator<<': 'bits_left'
}
