import pandas as pd


def batch_read_csv(filelist, **kwargs):
    """Batch-read a list of CSV files using pandas.read_csv."""
    list_df = [pd.read_csv(f, **kwargs) for f in filelist]
    return pd.concat(list_df, ignore_index=True)
